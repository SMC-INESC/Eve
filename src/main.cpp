#include <iostream>
#include <QtGui/QApplication>
#include "mainwindow.h"

#include "backend.h"
#include "MarSystemQtWrapper.h"

int main(int argc, char *argv[])
{    
    QApplication a(argc, argv);

    MainWindow *w = new MainWindow;
    w->show();

    return a.exec();
}
