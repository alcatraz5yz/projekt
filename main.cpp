#include "SnakeWindow.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[]) try{
    QApplication app(argc, argv);
    SnakeWindow window;
    window.showFullScreen();
    return app.exec();
}
catch(...) {
    qDebug() << "Unknown Error\n";
}