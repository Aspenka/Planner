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
    explicit YearWidget(QWidget *parent = nullptr);
    ~YearWidget();

private slots:
    void    setPreviousYear ();
    void    setNextYear     ();
    void    checkYear       ();

private:
    Ui::YearWidget  *mUi;
    int             mYear;

    QVector
    <CalendarWidget*> mCalendarVector;

    const QVector <eMonthValue> MONTHS =
    {JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY,
     AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER};

    void    resetCalendar           (int year);
    void    setCalendarWidget       ();
    void    clearCalendarVector     ();
    void    formCalendar            (int year);
    void    createCalendarWidget    (eMonthValue monthName, int year);
};

#endif // YEARWIDGET_H
