#ifndef CALENDARWIDGET_H
#define CALENDARWIDGET_H

#include <QWidget>
#include <QVector>
#include <QMap>
#include <QPixmap>
#include <QPainter>
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
    ~CalendarWidget() override;

    void    yearIsVisible   (bool f);

public slots:
    void    selectDay   (int day);
    void    unselectDay (int day);

signals:
    void    goToYear    ();
    void    goToMonth   ();
    void    goToDay     ();
    void    goToWeek    ();

private slots:
    void    selectWeek      ();
    void    unselectWeek    ();

private:
    Ui::CalendarWidget                      *mUi;
//    QMap <int,QVector <CalendarLabel *>>    mDaysVector;
    QVector <CalendarLabel *>   mDaysVector;
    QVector <CalendarLabel *>               mWeeksVector;
    int     mWeeksAmount;
    bool    mWeekSelect;
    QPoint  mCurrentWeekPos;

    const int DAYS_IN_WEEK = 7;

    void    fillCalendar        (eMonthValue month, int year = 0);
    void    setMonthName        (eMonthValue month);
    void    formWeeksContainer  (int size);
    void    connectWeeks        (int size);
    void    paintEvent          (QPaintEvent *event) override;
};

#endif // CALENDARWIDGET_H
