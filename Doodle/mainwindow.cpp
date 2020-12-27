/* ! \file mainwindow.cpp
*   \brief Файл содержит реализацию класса MainWindow
*   \author Охманович Андрей
*   \date 24.12.2020
*/
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "game.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    scene(new QGraphicsScene(this)),
    sceneMain(new QGraphicsScene(this)),
    view(new QGraphicsView(this)),
    game(new Game())
{
    initScene();
    showMainMenu();
}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief Меняет сцену
 */
void MainWindow::changeScene(QGraphicsScene *scene)
{
    view->setScene(scene);
}

/**
 * @brief Отображает экран главного меню
 */
void MainWindow::showMainMenu()
{
    sceneMain->setBackgroundBrush(QBrush(QImage(MAIN_MENU_PATH)));

    Button *playButton = new Button(PLAY_PATH, PLAY_HOVER_PATH);
    sceneMain->addItem(playButton);
    playButton->setPos(3*VIEW_WIDTH/4-BUTTON_WIDTH/2, 575);

    connect(playButton, SIGNAL(clicked()), this, SLOT(newGame()));
    changeScene(sceneMain);
}

/**
 * @brief Создает новую игру
 */
void MainWindow::newGame()
{
    scene->clear();
    delete game;
    game=new Game(*scene, *view, this);
    startGame();
}

void MainWindow::initScene()
{
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(VIEW_WIDTH,VIEW_HEIGHT);
    view->setSceneRect(0,0,VIEW_WIDTH,VIEW_HEIGHT);
    view->fitInView(0,0,VIEW_WIDTH,VIEW_HEIGHT,Qt::KeepAspectRatio);

    ui->setupUi(this);
    setCentralWidget(view);
}

/**
 * @brief Начинает игру
 */
void MainWindow::startGame()
{
    scene->setBackgroundBrush(QBrush(QImage(BACKGROUND_PATH)));
    changeScene(scene);
}

