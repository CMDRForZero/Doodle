/* ! \file game.h
*   \brief Файл содержит описание класса Game - игрового процесса
*   \author Охманович Андрей
*   \date 24.12.2020
*/
#ifndef GAME_H
#define GAME_H

#include <ctime>
#include <cstdlib>

#include <vector>

#include <QApplication>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QTimer>
#include <QList>
#include <QFont>

#include "define.h"
#include "doodle.h"
#include "button.h"
#include "mainwindow.h"
#include "platform.h"
#include "spawnplatform.h"


class Game: public QObject
{
    Q_OBJECT
public:
    Game();
    Game(QGraphicsScene &scene, QGraphicsView &view, QObject *parent=nullptr);
    QGraphicsItemGroup *platformGroup;

    std::vector<Platform *> plat;


private:
    void handleKeyPressed(QKeyEvent *event);
    void handleKeyRelease(QKeyEvent *event);

    void initialize();
    void initPlayer();
    void initPlatform();
    void initGameOverScene();


    QGraphicsScene *tempScene, &scene, *pauseScene, *gameOverScene;
    QGraphicsView *tempView, &view;
    QList<QGraphicsItem *> platformList;
    QTimer *timer;
    QGraphicsTextItem *label;

    Doodle *doodle;

    bool paused=false;
signals:
    void gameOver();
    void scoreUpdated();
public slots:
    void moveCamera();
    void entityMovementGeneration();
    void generatePlatform();
    void gameOverSlot();
protected:
    bool eventFilter(QObject *object, QEvent *event);
    void advance(int phase);
};

#endif // GAME_H
