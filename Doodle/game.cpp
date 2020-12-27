/* ! \file game.cpp
*   \brief Файл содержит реализацию класса Game
*   \author Охманович Андрей
*   \date 24.12.2020
*/
#include "game.h"

Game::Game():
    tempScene(new QGraphicsScene(this)),
    scene(*tempScene),
    tempView(new QGraphicsView()),
    view(*tempView)
{

}

Game::Game(QGraphicsScene &scene, QGraphicsView &view, QObject *parent):
    QObject(parent),
    scene(scene),
    pauseScene(new QGraphicsScene(this)),
    gameOverScene(new QGraphicsScene(this)),
    view(view),
    timer(new QTimer(this)),
    label(new QGraphicsTextItem),
    doodle(new Doodle(*this))
{

    srand(static_cast<unsigned>(time(nullptr)));

    scene.installEventFilter(this);

    timer->start(16);
    connect(timer, SIGNAL(timeout()), &scene, SLOT(advance()));
    connect(timer, SIGNAL(timeout()), this, SLOT(moveCamera()));
    connect(timer, SIGNAL(timeout()), this, SLOT(entityMovementGeneration()));
    connect(this, SIGNAL(gameOver()), this, SLOT(gameOverSlot()));

    initialize();
}

/**
 * @brief Устанавливает определенные условия в зависимости от того, какие клавиши нажаты
 * @param event: клавиша, которая была нажата
 */
void Game::handleKeyPressed(QKeyEvent *event)
{
    switch(event->key()){
        case Qt::Key_Left:
            doodle->moveDirection(LEFT);
            break;
        case Qt::Key_Right:
            doodle->moveDirection(RIGHT);
            break;
        case Qt::Key_Escape: case Qt::Key_P:
            if(paused==false){
                disconnect(timer, SIGNAL(timeout()), &scene, SLOT(advance()));
                disconnect(timer, SIGNAL(timeout()), this, SLOT(moveCamera()));
                disconnect(timer, SIGNAL(timeout()), this, SLOT(entityMovementGeneration()));
                disconnect(this, SIGNAL(gameOver()), this, SLOT(gameOverSlot()));

                paused=true;
            }
            else{
                connect(timer, SIGNAL(timeout()), &scene, SLOT(advance()));
                connect(timer, SIGNAL(timeout()), this, SLOT(moveCamera()));
                connect(timer, SIGNAL(timeout()), this, SLOT(entityMovementGeneration()));
                connect(this, SIGNAL(gameOver()), this, SLOT(gameOverSlot()));

                paused=false;
            }
            break;
    }
}

/**
 * @brief Устанавливает определенные условия в зависимости от того, какие ключи отпущены
 * @param event: Отпущенная клавиша
 */
void Game::handleKeyRelease(QKeyEvent *event)
{
    switch(event->key()){
        case Qt::Key_Left:
            if(doodle->checkMovingDirection(LEFT))
                doodle->moveDirection(STOP);
            break;
        case Qt::Key_Right:
            if(doodle->checkMovingDirection(RIGHT))
                doodle->moveDirection(STOP);
            break;
    }
}

void Game::initialize()
{
    initPlayer();
    initPlatform();
    initGameOverScene();
}

/**
 * @brief Добавляет на экран Дудлера
 */
void Game::initPlayer()
{
    doodle->setPos(VIEW_WIDTH/2-PLAYER_WIDTH/2,VIEW_HEIGHT/2);
    scene.addItem(doodle);
}

/**
 * @brief Добавляет на экран платформы
 */
void Game::initPlatform()
{
    Platform *platformPointer;
    for(unsigned long i=0;i<PLATFORM_ONSCREEN;i++){
        i==0?platformPointer=new GreenPlatform:platformPointer=randomPlatform();
        plat.push_back(platformPointer);
        plat.at(i)->setCoordinate(i==0?VIEW_WIDTH/2-PLATFORM_WIDTH/2:rand()%(VIEW_WIDTH-PLATFORM_WIDTH)
                                  ,(VIEW_HEIGHT-plat.at(i)->getHeight())-static_cast<int>(i)*((VIEW_HEIGHT-plat.at(i)->getHeight())/PLATFORM_ONSCREEN));
        plat.at(i)->setPos(plat.at(i)->X(),plat.at(i)->Y());
        platformList.append(plat.at(i));
    }
    platformGroup=scene.createItemGroup(platformList);
}

/**
 * @brief при проигрыше отображает экран Game Over
 */
void Game::initGameOverScene()
{
    gameOverScene->setBackgroundBrush(QBrush(QImage(BACKGROUND_PATH)));
}

/**
 * @brief Движение камеры
 */
void Game::moveCamera()
{
    if(doodle->y()<VIEW_HEIGHT/2-doodle->getPlayerHeight()){
        if(doodle->y()<VIEW_HEIGHT/2-doodle->getPlayerHeight()){
            doodle->setY(VIEW_HEIGHT/2-doodle->getPlayerHeight());
        }
        std::vector<Platform *>::iterator it=plat.begin();
        for(unsigned long i=0;it!=plat.end();it++, i++){
            if(doodle->getCurrentDirection()==UP){
                plat.at(i)->setY(plat.at(i)->y()+doodle->getDeltaY());
            }
        }
    }
}


void Game::entityMovementGeneration()
{
    generatePlatform();
}

/**
 * @brief Генерация платформ
 */
void Game::generatePlatform()
{

    if(plat.at(0)->y()>=VIEW_HEIGHT){
        double temp=VIEW_HEIGHT-plat.at(0)->y();
        platformList.removeAt(0);
        plat.erase(plat.begin());
        plat.push_back(randomPlatform());
        plat.back()->setCoordinate(rand()%(VIEW_WIDTH-PLATFORM_WIDTH),-1*temp);
        plat.back()->setPos(plat.back()->X(),plat.back()->Y());
                platformList.append(plat.back());
    }
    scene.destroyItemGroup(platformGroup);
    platformGroup=scene.createItemGroup(platformList);
}

/**
 * @brief Отображение элементов на экране Game Over
 */
void Game::gameOverSlot()
{
    disconnect(this, SIGNAL(gameOver()), this, SLOT(gameOverSlot()));
    disconnect(timer, SIGNAL(timeout()), this, SLOT(moveCamera()));
    disconnect(timer, SIGNAL(timeout()), this, SLOT(generatePlatform()));

    label->setFont(QFont("courier", 70));
    label->setDefaultTextColor(Qt::red);
    label->setPos(OFFSET+200,OFFSET+55);
    label->setZValue(2);
    label->setPlainText("GAME OVER");
    gameOverScene->addItem(label);

    Button *menuButton = new Button(MENU_PATH, MENU_HOVER_PATH);
    menuButton->setZValue(4);
    gameOverScene->addItem(menuButton);
    menuButton->setPos(3*VIEW_WIDTH/4-BUTTON_WIDTH/2, 575);

    connect(menuButton, SIGNAL(clicked()), QApplication::activeWindow(), SLOT(showMainMenu()));

    view.setScene(gameOverScene);
}

bool Game::eventFilter(QObject *object, QEvent *event)
{
    if(event->type()==QEvent::KeyPress){
        handleKeyPressed(static_cast<QKeyEvent *>(event));
        return true;
    }
    else if(event->type()==QEvent::KeyRelease){
        handleKeyRelease(static_cast<QKeyEvent *>(event));
        return true;
    }
    else{
        return QObject::eventFilter(object, event);
    }
}
