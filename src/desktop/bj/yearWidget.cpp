#include "yearWidget.h"
#include "ui_yearWidget.h"
#include <QDate>

YearWidget::YearWidget(int year, QWidget *parent) :
    QWidget(parent), mUi(new Ui::YearWidget), mYear(year)
{
    mUi->setupUi(this);

    if(mYear == 0)
    {
        mYear = QDate::currentDate().year();
    }
    mUi->yearLabel->setText(QString::number(mYear));

    createCalendar(JANUARY);
    createCalendar(FEBRUARY);
    createCalendar(MARCH);
    createCalendar(APRIL);
    createCalendar(MAY);
    createCalendar(JUNE);
    createCalendar(JULY);
    createCalendar(AUGUST);
    createCalendar(SEPTEMBER);
    createCalendar(OCTOBER);
    createCalendar(NOVEMBER);
    createCalendar(DECEMBER);

    int i =0;
    int j = 0;
    foreach(CalendarWidget *month, mCalendarVector)
    {
        mUi->monthLayout->addWidget(month, i, j);
        ++j;
        if(j >= 4)
        {
            ++i; j = 0;
        }
    }
}

YearWidget::~YearWidget()
{
    if(!mCalendarVector.isEmpty())
    {
        qDeleteAll(mCalendarVector);
        mCalendarVector.clear();
    }
    delete mUi;
}

void YearWidget::createCalendar(eMonthValue monthName)
{
    CalendarWidget *month = new CalendarWidget(monthName);
    mCalendarVector.append(month);
}
