/* ! \file doodle.cpp
*   \brief Файл содержит реализацию класса Doodle
*   \author Охманович Андрей
*   \date 24.12.2020
*/
#include "doodle.h"
#include "game.h"
#include <QDebug>

/**
 * @brief Создает игрока
 */
Doodle::Doodle(Game &controller):
    controller(controller),
    currentDirection(DOWN),
    movingDirection(STOP),
    initialVelocity(20),
    gravity(0.65)
{
    connect(this, SIGNAL(upSignal()), this, SLOT(moveUp()));
    connect(this, SIGNAL(downSignal()), this, SLOT(moveDown()));
    connect(this, SIGNAL(leftSignal()), this, SLOT(moveLeft()));
    connect(this, SIGNAL(rightSignal()), this, SLOT(moveRight()));

    setShapeMode(QGraphicsPixmapItem::HeuristicMaskShape);
    setZValue(2);

    deltaY=initialVelocity;
    QPixmap pix;
    pix.load(PLAYER_RIGHT_PATH);

    setPixmap(pix.scaledToWidth(PLAYER_WIDTH));
    playerHeight=pix.scaledToWidth(PLAYER_WIDTH).height();
}

/**
 * @brief Движения дудлера
 */
void Doodle::moveDirection(horizontalDirection direction)
{
    if(movingDirection==LEFT&&direction==LEFT)
        return;
    if(movingDirection==RIGHT&&direction==RIGHT)
        return;
    movingDirection=direction;
}

/**
 * @brief Проверка движения дудлера
 */
bool Doodle::checkMovingDirection(horizontalDirection direction)
{
    return (direction==movingDirection)?true:false;
}

/**
 * @brief Взаиможействие с платформой
 */
bool Doodle::collidesWithPlatform()
{
    QList<QGraphicsItem *> collisions=this->collidingItems();
    if(scene()->collidingItems(this).isEmpty()){
        return false;
    }
    else{
        foreach(QGraphicsItem *collidingItem, collisions){
            if(collidingItem->data(TYPE)==PLATFORM&&collidingItem->y()-playerHeight+OFFSET>=y()){
                    distanceToGround=VIEW_HEIGHT-collidingItem->y();
                    previousY=static_cast<Platform *>(collidingItem)->y();

                return true;
            }
        }
        return false;
    }
}

double Doodle::getDeltaY() const
{
    return deltaY;
}

/**
 * @brief Прыжок
 */
void Doodle::jump()
{
    setFall(UP);
    deltaY=initialVelocity;
}

/**
 * @brief Падение
 */
void Doodle::setFall(verticalDirection direction)
{
    if(currentDirection==UP&&direction==UP){
        return;
    }
    if(currentDirection==DOWN&&direction==DOWN){
        return;
    }
    currentDirection=direction;
}

qreal Doodle::getDistanceToGround() const
{
    return distanceToGround;
}

verticalDirection Doodle::getCurrentDirection() const
{
    return currentDirection;
}

qreal Doodle::getPlayerHeight() const
{
    return playerHeight;
}

double Doodle::getGravity() const
{
    return gravity;
}

void Doodle::setDeltaY(double value)
{
    deltaY = value;
}

void Doodle::moveUp()
{
    deltaY-=gravity;
    setPos(x(), y()-deltaY);
    if(deltaY<=0){
        setFall(DOWN);
        deltaY=0;
    }
}

void Doodle::moveDown()
{
    deltaY+=(gravity);
    setPos(x(), y()+deltaY);
    if(y()+playerHeight>VIEW_HEIGHT){
        emit controller.gameOver();
    }
}

void Doodle::moveLeft()
{
    QPixmap pix;
    pix.load(PLAYER_LEFT_PATH);
    setPixmap(pix.scaledToWidth(PLAYER_WIDTH));

    setPos(x()-8,y());
    if(x()+PLAYER_WIDTH/2<=0){
        setPos(VIEW_WIDTH-PLAYER_WIDTH/2,y());
    }
}

void Doodle::moveRight()
{
    QPixmap pix;
    pix.load(PLAYER_RIGHT_PATH);
    setPixmap(pix.scaledToWidth(PLAYER_WIDTH));

    setPos(x()+8,y());
    if(x()>=VIEW_WIDTH-PLAYER_WIDTH/2){
        setPos(-1*PLAYER_WIDTH/2,y());
    }
}

void Doodle::advance(int phase)
{
    if(!phase){
        return;
    }

    switch(currentDirection){
        case UP:
            emit upSignal();
            break;
        case DOWN:
            emit downSignal();
            if(collidesWithPlatform()){
                jump();
            }
            break;
    }
    switch(movingDirection){
        case LEFT:
            emit leftSignal();
            break;
        case RIGHT:
            emit rightSignal();
            break;
        case STOP:
            break;
    }
}
