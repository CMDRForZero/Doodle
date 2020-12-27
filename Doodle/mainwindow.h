/* ! \file mainwindow.h
*   \brief Файл содержит описание класса MainWindow - экрана меню
*   \author Охманович Андрей
*   \date 24.12.2020
*/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "define.h"

class Game;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void changeScene(QGraphicsScene *scene);
public slots:
    void showMainMenu();
    void newGame();
private:
    Ui::MainWindow *ui;

    void initScene();
    void startGame();

    QGraphicsScene *scene, *sceneMain;
    QGraphicsView *view;

    Game *game;
};

#endif // MAINWINDOW_H
