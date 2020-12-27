/* ! \file doodle.h
*   \brief Файл содержит описание класса Doodle - игрока (Дудлера)
*   \author Охманович Андрей
*   \date 24.12.2020
*/
#ifndef DOODLE_H
#define DOODLE_H


#include <vector>
#include <algorithm>

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

#include "define.h"



class Game;

/**
 * @brief Играбельный персонаж
 */

class Doodle: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Doodle(Game &controller);

    void moveDirection(horizontalDirection direction);
    bool checkMovingDirection(horizontalDirection direction);
    bool collidesWithPlatform();
    double getDeltaY() const;
    void jump();
    void setDeltaY(double value);
    void setFall(verticalDirection direction);
    qreal getDistanceToGround() const;
    verticalDirection getCurrentDirection() const;
    qreal getPlayerHeight() const;
    double getGravity() const;

    double previousY;
private:
    Game &controller; //Этот параметр создается для того чтобы сообщить игре когда персонаж умирает

    qreal playerHeight, distanceToGround;
    verticalDirection currentDirection;
    horizontalDirection movingDirection;

    const double initialVelocity, gravity;
    double deltaY=25;
signals:
    void upSignal();
    void downSignal();
    void leftSignal();
    void rightSignal();
public slots:
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
protected:
    void advance(int phase);
};

#endif // DOODLE_H
