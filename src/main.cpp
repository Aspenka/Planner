/*!
    @file main.cpp
    @author Поспелова Ирина
*/
#include <QApplication>
#include "desktop/bj/taskWidget.h"

int main(int argc, char **argv)
{
    QApplication a(argc, argv);

    TaskWidget w;
    w.addTitle("Планы");
    w.show();

    return a.exec();
}
