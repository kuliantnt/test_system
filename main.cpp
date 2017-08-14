#include "mainwindow.h"
#include <QApplication>
#include <QtCore/QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    return a.exec();
}
