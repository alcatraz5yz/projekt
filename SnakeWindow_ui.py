# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'SnakeWindow.ui'
##
## Created by: Qt User Interface Compiler version 6.5.2
##
## WARNING! All changes made in this file will be lost when recompiling UI file!
################################################################################

from PySide6.QtCore import (QCoreApplication, QDate, QDateTime, QLocale,
    QMetaObject, QObject, QPoint, QRect,
    QSize, QTime, QUrl, Qt)
from PySide6.QtGui import (QBrush, QColor, QConicalGradient, QCursor,
    QFont, QFontDatabase, QGradient, QIcon,
    QImage, QKeySequence, QLinearGradient, QPainter,
    QPalette, QPixmap, QRadialGradient, QTransform)
from PySide6.QtWidgets import (QApplication, QFrame, QGridLayout, QLCDNumber,
    QLabel, QPushButton, QSizePolicy, QWidget)

from SnakeBoard import SnakeBoard

class Ui_SnakeWindow(object):
    def setupUi(self, SnakeWindow):
        if not SnakeWindow.objectName():
            SnakeWindow.setObjectName(u"SnakeWindow")
        SnakeWindow.resize(771, 618)
        SnakeWindow.setStyleSheet(u"")
        self.gridLayout = QGridLayout(SnakeWindow)
        self.gridLayout.setObjectName(u"gridLayout")
        self.delayLcd = QLCDNumber(SnakeWindow)
        self.delayLcd.setObjectName(u"delayLcd")
        sizePolicy = QSizePolicy(QSizePolicy.Preferred, QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(1)
        sizePolicy.setHeightForWidth(self.delayLcd.sizePolicy().hasHeightForWidth())
        self.delayLcd.setSizePolicy(sizePolicy)
        font = QFont()
        font.setPointSize(20)
        self.delayLcd.setFont(font)
        self.delayLcd.setStyleSheet(u"background-color: rgb(255, 255, 127);")
        self.delayLcd.setSmallDecimalPoint(False)
        self.delayLcd.setDigitCount(5)
        self.delayLcd.setMode(QLCDNumber.Dec)
        self.delayLcd.setSegmentStyle(QLCDNumber.Flat)

        self.gridLayout.addWidget(self.delayLcd, 1, 2, 1, 2)

        self.snakeBoard = SnakeBoard(SnakeWindow)
        self.snakeBoard.setObjectName(u"snakeBoard")
        sizePolicy1 = QSizePolicy(QSizePolicy.Preferred, QSizePolicy.Preferred)
        sizePolicy1.setHorizontalStretch(0)
        sizePolicy1.setVerticalStretch(8)
        sizePolicy1.setHeightForWidth(self.snakeBoard.sizePolicy().hasHeightForWidth())
        self.snakeBoard.setSizePolicy(sizePolicy1)
        self.snakeBoard.setStyleSheet(u"background-color:\n"
"                                          qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0\n"
"                                          rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61,\n"
"                                          255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0,\n"
"                                          0));")
        self.snakeBoard.setFrameShape(QFrame.StyledPanel)
        self.snakeBoard.setFrameShadow(QFrame.Raised)

        self.gridLayout.addWidget(self.snakeBoard, 2, 0, 1, 4)

        self.quitButton = QPushButton(SnakeWindow)
        self.quitButton.setObjectName(u"quitButton")
        sizePolicy2 = QSizePolicy(QSizePolicy.Minimum, QSizePolicy.Minimum)
        sizePolicy2.setHorizontalStretch(0)
        sizePolicy2.setVerticalStretch(1)
        sizePolicy2.setHeightForWidth(self.quitButton.sizePolicy().hasHeightForWidth())
        self.quitButton.setSizePolicy(sizePolicy2)
        self.quitButton.setFont(font)
        self.quitButton.setFocusPolicy(Qt.NoFocus)
        self.quitButton.setStyleSheet(u"\n"
"                                          background-color: rgb(255, 170, 255);")

        self.gridLayout.addWidget(self.quitButton, 3, 3, 1, 1)

        self.scoreLabel = QLabel(SnakeWindow)
        self.scoreLabel.setObjectName(u"scoreLabel")
        sizePolicy3 = QSizePolicy(QSizePolicy.Preferred, QSizePolicy.Maximum)
        sizePolicy3.setHorizontalStretch(0)
        sizePolicy3.setVerticalStretch(0)
        sizePolicy3.setHeightForWidth(self.scoreLabel.sizePolicy().hasHeightForWidth())
        self.scoreLabel.setSizePolicy(sizePolicy3)
        font1 = QFont()
        font1.setPointSize(20)
        font1.setBold(False)
        self.scoreLabel.setFont(font1)
        self.scoreLabel.setAlignment(Qt.AlignCenter)

        self.gridLayout.addWidget(self.scoreLabel, 0, 0, 1, 1)

        self.scoreLcd = QLCDNumber(SnakeWindow)
        self.scoreLcd.setObjectName(u"scoreLcd")
        sizePolicy.setHeightForWidth(self.scoreLcd.sizePolicy().hasHeightForWidth())
        self.scoreLcd.setSizePolicy(sizePolicy)
        self.scoreLcd.setFont(font)
        self.scoreLcd.setStyleSheet(u"background-color: rgb(255, 255, 127);")
        self.scoreLcd.setSmallDecimalPoint(False)
        self.scoreLcd.setDigitCount(10)
        self.scoreLcd.setSegmentStyle(QLCDNumber.Flat)

        self.gridLayout.addWidget(self.scoreLcd, 1, 0, 1, 2)

        self.delayLabel = QLabel(SnakeWindow)
        self.delayLabel.setObjectName(u"delayLabel")
        sizePolicy3.setHeightForWidth(self.delayLabel.sizePolicy().hasHeightForWidth())
        self.delayLabel.setSizePolicy(sizePolicy3)
        self.delayLabel.setFont(font1)
        self.delayLabel.setAlignment(Qt.AlignCenter)

        self.gridLayout.addWidget(self.delayLabel, 0, 2, 1, 2)

        self.startButton = QPushButton(SnakeWindow)
        self.startButton.setObjectName(u"startButton")
        sizePolicy2.setHeightForWidth(self.startButton.sizePolicy().hasHeightForWidth())
        self.startButton.setSizePolicy(sizePolicy2)
        self.startButton.setFont(font)
        self.startButton.setFocusPolicy(Qt.NoFocus)
        self.startButton.setStyleSheet(u"background-color: rgb(85, 255, 0);")

        self.gridLayout.addWidget(self.startButton, 3, 0, 1, 1)

        self.pauseButton = QPushButton(SnakeWindow)
        self.pauseButton.setObjectName(u"pauseButton")
        sizePolicy2.setHeightForWidth(self.pauseButton.sizePolicy().hasHeightForWidth())
        self.pauseButton.setSizePolicy(sizePolicy2)
        self.pauseButton.setFont(font)
        self.pauseButton.setFocusPolicy(Qt.NoFocus)
        self.pauseButton.setStyleSheet(u"background-color: rgb(170, 255, 0);")

        self.gridLayout.addWidget(self.pauseButton, 3, 1, 1, 1)


        self.retranslateUi(SnakeWindow)

        QMetaObject.connectSlotsByName(SnakeWindow)
    # setupUi

    def retranslateUi(self, SnakeWindow):
        SnakeWindow.setWindowTitle(QCoreApplication.translate("SnakeWindow", u"Snake", None))
        self.quitButton.setText(QCoreApplication.translate("SnakeWindow", u"Quit", None))
        self.scoreLabel.setText(QCoreApplication.translate("SnakeWindow", u"Score", None))
        self.delayLabel.setText(QCoreApplication.translate("SnakeWindow", u"Delay in ms", None))
        self.startButton.setText(QCoreApplication.translate("SnakeWindow", u"Start", None))
        self.pauseButton.setText(QCoreApplication.translate("SnakeWindow", u"Pause", None))
    # retranslateUi

