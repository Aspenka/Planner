#ifndef CALENDARWIDGET_H
#define CALENDARWIDGET_H

#include <QWidget>
#include <QVector>
#include "calendarLabel.h"
#include "../common/common.h"

namespace Ui {
class CalendarWidget;
}

class CalendarWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CalendarWidget(eMonthValue month, int year = 0, QWidget *parent = nullptr);
    ~CalendarWidget();

signals:
    void    goToYear    ();
    void    goToMonth   ();
    void    goToDay     ();

    //slots?
    void    yearContext     ();
    void    monthContext    ();
    void    dayContext      ();

private:
    Ui::CalendarWidget *mUi;
    QVector <CalendarLabel *>  mDaysVector;

    const int DAYS_IN_WEEK = 7;

    void    fillCalendar    (eMonthValue month, int year = 0);
    void    setMonthName    (eMonthValue month);
};

#endif // CALENDARWIDGET_H
