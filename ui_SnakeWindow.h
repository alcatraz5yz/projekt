/********************************************************************************
** Form generated from reading UI file 'SnakeWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SNAKEWINDOW_H
#define UI_SNAKEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <SnakeBoard.h>

QT_BEGIN_NAMESPACE

class Ui_SnakeWindow
{
public:
    QGridLayout *gridLayout;
    QLCDNumber *delayLcd;
    SnakeBoard *snakeBoard;
    QPushButton *quitButton;
    QLabel *scoreLabel;
    QLCDNumber *scoreLcd;
    QLabel *delayLabel;
    QPushButton *startButton;
    QPushButton *pauseButton;

    void setupUi(QWidget *SnakeWindow)
    {
        if (SnakeWindow->objectName().isEmpty())
            SnakeWindow->setObjectName("SnakeWindow");
        SnakeWindow->resize(771, 618);
        SnakeWindow->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(SnakeWindow);
        gridLayout->setObjectName("gridLayout");
        delayLcd = new QLCDNumber(SnakeWindow);
        delayLcd->setObjectName("delayLcd");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(delayLcd->sizePolicy().hasHeightForWidth());
        delayLcd->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(20);
        delayLcd->setFont(font);
        delayLcd->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 127);"));
        delayLcd->setSmallDecimalPoint(false);
        delayLcd->setDigitCount(5);
        delayLcd->setMode(QLCDNumber::Dec);
        delayLcd->setSegmentStyle(QLCDNumber::Flat);

        gridLayout->addWidget(delayLcd, 1, 2, 1, 2);

        snakeBoard = new SnakeBoard(SnakeWindow);
        snakeBoard->setObjectName("snakeBoard");
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(8);
        sizePolicy1.setHeightForWidth(snakeBoard->sizePolicy().hasHeightForWidth());
        snakeBoard->setSizePolicy(sizePolicy1);
        snakeBoard->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));"));
        snakeBoard->setFrameShape(QFrame::StyledPanel);
        snakeBoard->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(snakeBoard, 2, 0, 1, 4);

        quitButton = new QPushButton(SnakeWindow);
        quitButton->setObjectName("quitButton");
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(1);
        sizePolicy2.setHeightForWidth(quitButton->sizePolicy().hasHeightForWidth());
        quitButton->setSizePolicy(sizePolicy2);
        quitButton->setFont(font);
        quitButton->setFocusPolicy(Qt::NoFocus);
        quitButton->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(255, 170, 255);"));

        gridLayout->addWidget(quitButton, 3, 3, 1, 1);

        scoreLabel = new QLabel(SnakeWindow);
        scoreLabel->setObjectName("scoreLabel");
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(scoreLabel->sizePolicy().hasHeightForWidth());
        scoreLabel->setSizePolicy(sizePolicy3);
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(false);
        scoreLabel->setFont(font1);
        scoreLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(scoreLabel, 0, 0, 1, 1);

        scoreLcd = new QLCDNumber(SnakeWindow);
        scoreLcd->setObjectName("scoreLcd");
        sizePolicy.setHeightForWidth(scoreLcd->sizePolicy().hasHeightForWidth());
        scoreLcd->setSizePolicy(sizePolicy);
        scoreLcd->setFont(font);
        scoreLcd->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 127);"));
        scoreLcd->setSmallDecimalPoint(false);
        scoreLcd->setDigitCount(10);
        scoreLcd->setSegmentStyle(QLCDNumber::Flat);

        gridLayout->addWidget(scoreLcd, 1, 0, 1, 2);

        delayLabel = new QLabel(SnakeWindow);
        delayLabel->setObjectName("delayLabel");
        sizePolicy3.setHeightForWidth(delayLabel->sizePolicy().hasHeightForWidth());
        delayLabel->setSizePolicy(sizePolicy3);
        delayLabel->setFont(font1);
        delayLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(delayLabel, 0, 2, 1, 2);

        startButton = new QPushButton(SnakeWindow);
        startButton->setObjectName("startButton");
        sizePolicy2.setHeightForWidth(startButton->sizePolicy().hasHeightForWidth());
        startButton->setSizePolicy(sizePolicy2);
        startButton->setFont(font);
        startButton->setFocusPolicy(Qt::NoFocus);
        startButton->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 255, 0);"));

        gridLayout->addWidget(startButton, 3, 0, 1, 1);

        pauseButton = new QPushButton(SnakeWindow);
        pauseButton->setObjectName("pauseButton");
        sizePolicy2.setHeightForWidth(pauseButton->sizePolicy().hasHeightForWidth());
        pauseButton->setSizePolicy(sizePolicy2);
        pauseButton->setFont(font);
        pauseButton->setFocusPolicy(Qt::NoFocus);
        pauseButton->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 255, 0);"));

        gridLayout->addWidget(pauseButton, 3, 1, 1, 1);


        retranslateUi(SnakeWindow);

        QMetaObject::connectSlotsByName(SnakeWindow);
    } // setupUi

    void retranslateUi(QWidget *SnakeWindow)
    {
        SnakeWindow->setWindowTitle(QCoreApplication::translate("SnakeWindow", "Snake", nullptr));
        quitButton->setText(QCoreApplication::translate("SnakeWindow", "Quit", nullptr));
        scoreLabel->setText(QCoreApplication::translate("SnakeWindow", "Score", nullptr));
        delayLabel->setText(QCoreApplication::translate("SnakeWindow", "Delay in ms", nullptr));
        startButton->setText(QCoreApplication::translate("SnakeWindow", "Start", nullptr));
        pauseButton->setText(QCoreApplication::translate("SnakeWindow", "Pause", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SnakeWindow: public Ui_SnakeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SNAKEWINDOW_H
