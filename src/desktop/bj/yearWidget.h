#ifndef YEARWIDGET_H
#define YEARWIDGET_H

#include <QWidget>
#include <QVector>
#include "calendarWidget.h"

namespace Ui {
class YearWidget;
}

class YearWidget : public QWidget
{
    Q_OBJECT

public:
    explicit YearWidget(int year = 0, QWidget *parent = nullptr);
    ~YearWidget();

private:
    Ui::YearWidget  *mUi;
    int             mYear;

    QVector
    <CalendarWidget*> mCalendarVector;

    void    createCalendar  (eMonthValue monthName);
};

#endif // YEARWIDGET_H
