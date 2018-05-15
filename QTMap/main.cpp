#include "mw1.h"
#include "menuwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    MenuWindow menu;
    menu.show();

    return a.exec();
}
