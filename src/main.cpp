/*!
    @file main.cpp
    @author Поспелова Ирина
*/
#include <QApplication>
#include "desktop/bj/yearWidget.h"

int main(int argc, char **argv)
{
    QApplication a(argc, argv);

    YearWidget w;
    w.show();

    return a.exec();
}
