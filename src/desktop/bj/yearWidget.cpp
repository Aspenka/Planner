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
    mUi->yearLabel->setSelectable(true);
    mUi->prevLabel->setSelectable(true);
    mUi->nextLabel->setSelectable(true);

    connect(mUi->yearLabel, &CalendarLabel::leftClicked,
            this, &YearWidget::checkYear);
    connect(mUi->nextLabel, &CalendarLabel::leftClicked,
            this, &YearWidget::setNextYear);
    connect(mUi->prevLabel, &CalendarLabel::leftClicked,
            this, &YearWidget::setPreviousYear);

    formCalendar(mYear);
    setCalendarWidget();

}

YearWidget::~YearWidget()
{
    if(!mCalendarVector.isEmpty())
    {
        clearCalendarVector();
    }
    delete mUi;
}

void YearWidget::setPreviousYear()
{
    --mYear;
    if(mYear > 0)
    {
        resetCalendar(mYear);
    }
}

void YearWidget::setNextYear()
{
    ++mYear;
    resetCalendar(mYear);
}

void YearWidget::checkYear()
{
    //Заглушка
}

void YearWidget::resetCalendar(int year)
{
    mUi->yearLabel->setText(QString::number(year));
    clearCalendarVector();
    formCalendar(mYear);
    setCalendarWidget();
}

void YearWidget::setCalendarWidget()
{
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

void YearWidget::clearCalendarVector()
{
    qDeleteAll(mCalendarVector);
    mCalendarVector.clear();
}

void YearWidget::formCalendar(int year)
{
    foreach(eMonthValue val, MONTHS)
    {
        createCalendarWidget(val, year);
    }
}

void YearWidget::createCalendarWidget(eMonthValue monthName, int year)
{
    CalendarWidget *month = new CalendarWidget(monthName, year);
    month->yearIsVisible(false);
    mCalendarVector.append(month);
    //connections
}
