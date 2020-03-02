/*!
    @file main.cpp
    @author Поспелова Ирина
*/
#include <QApplication>
#include "desktop/bj/calendarWidget.h"

int main(int argc, char **argv)
{
    QApplication a(argc, argv);

    CalendarWidget w(DECEMBER, 2019);
    w.show();

    return a.exec();
}
