#include "calendarWidget.h"
#include "ui_calendarWidget.h"
#include <QLabel>
#include <QDate>

CalendarWidget::CalendarWidget(eMonthValue month, int year, QWidget *parent) :
    QWidget(parent), mUi(new Ui::CalendarWidget)
{
    mUi->setupUi(this);
    fillCalendar(month, year);
}

CalendarWidget::~CalendarWidget()
{
    if(!mDaysVector.isEmpty())
    {
        qDeleteAll(mDaysVector);
        mDaysVector.clear();
    }
    delete mUi;
}

void CalendarWidget::fillCalendar(eMonthValue month, int year)
{
    if(year == 0)
    {
        year = QDate::currentDate().year();
    }
    else
    {
        mUi->yearLabel->setText(QString::number(year))  ;
    }
    setMonthName(month);
    int currentDay = 1;
    QDate date(year, month, 1);
    int i = date.dayOfWeek();
    int size = date.daysInMonth();
    int currentRow = 1;
    for( ; currentDay <= size; ++currentDay)
    {
        QLabel *day = new QLabel(QString::number(currentDay));
        mDaysVector.push_back(day);
        mUi->bodyLayout->addWidget(day, currentRow, i);
        ++i;
        if(i > DAYS_IN_WEEK)
        {
            i = 1;
            ++currentRow;
        }
    }
}

void CalendarWidget::setMonthName(eMonthValue month)
{
    switch (month)
    {
        case JANUARY:
        {
            mUi->monthLabel->setText(tr("Январь"));
            break;
        }
        case FEBRUARY:
        {
            mUi->monthLabel->setText(tr("Февраль"));
            break;
        }
        case MARCH:
        {
            mUi->monthLabel->setText(tr("Март"));
            break;
        }
        case APRIL:
        {
            mUi->monthLabel->setText(tr("Апрель"));
            break;
        }
        case MAY:
        {
            mUi->monthLabel->setText(tr("Май"));
            break;
        }
        case JUNE:
        {
            mUi->monthLabel->setText(tr("Июнь"));
            break;
        }
        case JULY:
        {
            mUi->monthLabel->setText(tr("Июль"));
            break;
        }
        case AUGUST:
        {
            mUi->monthLabel->setText(tr("Август"));
            break;
        }
        case SEPTEMBER:
        {
            mUi->monthLabel->setText(tr("Сентябрь"));
            break;
        }
        case OCTOBER:
        {
            mUi->monthLabel->setText(tr("Октябрь"));
            break;
        }
        case NOVEMBER:
        {
            mUi->monthLabel->setText(tr("Ноябрь"));
            break;
        }
        case DECEMBER:
        {
            mUi->monthLabel->setText(tr("Декабрь"));
            break;
        }
    }
}
