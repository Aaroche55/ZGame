/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTextEdit *outputTextEdit;
    QHBoxLayout *buttonLayout;
    QPushButton *forwardButton;
    QPushButton *backButton;
    QPushButton *leftButton;
    QPushButton *rightButton;
    QHBoxLayout *actionButtonLayout;
    QPushButton *searchButton;
    QPushButton *takeButton;
    QLineEdit *commandLineEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        outputTextEdit = new QTextEdit(centralwidget);
        outputTextEdit->setObjectName("outputTextEdit");
        outputTextEdit->setReadOnly(true);

        verticalLayout->addWidget(outputTextEdit);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setObjectName("buttonLayout");
        forwardButton = new QPushButton(centralwidget);
        forwardButton->setObjectName("forwardButton");

        buttonLayout->addWidget(forwardButton);

        backButton = new QPushButton(centralwidget);
        backButton->setObjectName("backButton");

        buttonLayout->addWidget(backButton);

        leftButton = new QPushButton(centralwidget);
        leftButton->setObjectName("leftButton");

        buttonLayout->addWidget(leftButton);

        rightButton = new QPushButton(centralwidget);
        rightButton->setObjectName("rightButton");

        buttonLayout->addWidget(rightButton);


        verticalLayout->addLayout(buttonLayout);

        actionButtonLayout = new QHBoxLayout();
        actionButtonLayout->setObjectName("actionButtonLayout");
        searchButton = new QPushButton(centralwidget);
        searchButton->setObjectName("searchButton");

        actionButtonLayout->addWidget(searchButton);

        takeButton = new QPushButton(centralwidget);
        takeButton->setObjectName("takeButton");

        actionButtonLayout->addWidget(takeButton);


        verticalLayout->addLayout(actionButtonLayout);

        commandLineEdit = new QLineEdit(centralwidget);
        commandLineEdit->setObjectName("commandLineEdit");

        verticalLayout->addWidget(commandLineEdit);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Zgame", nullptr));
        forwardButton->setText(QCoreApplication::translate("MainWindow", "Forward", nullptr));
        backButton->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        leftButton->setText(QCoreApplication::translate("MainWindow", "Left", nullptr));
        rightButton->setText(QCoreApplication::translate("MainWindow", "Right", nullptr));
        searchButton->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        takeButton->setText(QCoreApplication::translate("MainWindow", "Take", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
