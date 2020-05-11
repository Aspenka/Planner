/*!
    @file main.cpp
    @author Поспелова Ирина
*/
#include <QApplication>
#include "desktop/bj/plannerWidget.h"

int main(int argc, char **argv)
{
    QApplication a(argc, argv);

    PlannerWidget w;
    w.show();

    return a.exec();
}
