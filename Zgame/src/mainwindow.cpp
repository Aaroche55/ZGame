#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMainWindow>

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow),
        gameEngine(new Game::GameEngine())
{
    ui->setupUi(this);
    connect(gameEngine, &Game::GameEngine::textOutput, this, &MainWindow::updateOutputText);
    connect(ui->takeButton, &QPushButton::clicked, this, &MainWindow::onTakeButtonClicked);
    connect(ui->forwardButton, &QPushButton::clicked, this, &MainWindow::onForwardButtonClicked);
    connect(ui->backButton, &QPushButton::clicked, this, &MainWindow::onBackButtonClicked);
    connect(ui->leftButton, &QPushButton::clicked, this, &MainWindow::onLeftButtonClicked);
    connect(ui->rightButton, &QPushButton::clicked, this, &MainWindow::onRightButtonClicked);
    connect(ui->searchButton, &QPushButton::clicked, this, &MainWindow::onSearchButtonClicked);
    gameEngine->start(); // Call GameEngine method
}


MainWindow::~MainWindow() {
    delete ui;
    delete gameEngine;
}

void MainWindow::updateOutputText(const QString& text) {
    ui->outputTextEdit->append(text);
}

void MainWindow::onTakeButtonClicked() {
    gameEngine->takeItem(); // Call GameEngine method
}

void MainWindow::onForwardButtonClicked() {
    gameEngine->movePlayer(Game::Forward); // Call GameEngine method
}

void MainWindow::onBackButtonClicked() {
    gameEngine->movePlayer(Game::Backward); // Call GameEngine method
}

void MainWindow::onLeftButtonClicked() {
    gameEngine->movePlayer(Game::Left); // Call GameEngine method
}

void MainWindow::onRightButtonClicked() {
    gameEngine->movePlayer(Game::Right); // Call GameEngine method
}

void MainWindow::onSearchButtonClicked() {
    gameEngine->lookAround(); // Call GameEngine method
}
