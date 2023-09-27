#include "SnakeWindow.h"
#include "ui_SnakeWindow.h"

SnakeWindow::SnakeWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SnakeWindow) {
    ui->setupUi(this);
    connect(ui->startButton, &QPushButton::clicked, ui->snakeBoard, &SnakeBoard::start);
    connect(ui->quitButton, &QPushButton::clicked, qApp, &QApplication::quit);
    connect(ui->pauseButton, &QPushButton::clicked, ui->snakeBoard, &SnakeBoard::pause);
    connect(ui->snakeBoard, &SnakeBoard::scoreChanged, [=](int score) {ui->scoreLcd->display(score);});
    connect(ui->snakeBoard, &SnakeBoard::delayChanged, [=](int level) {ui->delayLcd->display(level);});
}

SnakeWindow::~SnakeWindow() { delete ui; }