#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gameengine.h" // Include GameEngine header

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void updateOutputText(const QString& text);
    void onTakeButtonClicked();
    void onForwardButtonClicked();
    void onBackButtonClicked();
    void onLeftButtonClicked();
    void onRightButtonClicked();
    void onSearchButtonClicked();


private:
    Ui::MainWindow *ui;
    Game::GameEngine *gameEngine; // Correct namespace and type
};

#endif // MAINWINDOW_H
