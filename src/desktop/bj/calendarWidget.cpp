#include "calendarWidget.h"
#include "ui_calendarWidget.h"
#include <QDate>
#include <QMenu>
#include <QtGlobal>
#include <QPaintEvent>
#include <QDebug>

CalendarWidget::CalendarWidget(eMonthValue month, int year, QWidget *parent) :
    QWidget(parent), mUi(new Ui::CalendarWidget), mWeeksAmount(0),
    mWeekSelect(false), mCurrentWeekPos(0, 0)
{
    this->setAttribute(Qt::WA_Hover);
    this->setMouseTracking(true);
    mUi->setupUi(this);
    fillCalendar(month, year); 
}

CalendarWidget::~CalendarWidget()
{
    if(!mDaysVector.isEmpty())
    {
        foreach(QVector<CalendarLabel*> vector, mDaysVector.values())
        {
            qDeleteAll(vector);
            vector.clear();
        }
        mDaysVector.clear();
    }
    delete mUi;
}

void CalendarWidget::selectWeek()
{
    mWeekSelect = true;
    CalendarLabel *label = static_cast<CalendarLabel*>(sender());
    mCurrentWeekPos = label->pos();
}

void CalendarWidget::unselectWeek()
{
    mWeekSelect = false;
    CalendarLabel *label = static_cast<CalendarLabel*>(sender());
    mCurrentWeekPos = label->pos();
}

void CalendarWidget::fillCalendar(eMonthValue month, int year)
{ 
    if(year != 0)
    {
        mUi->yearLabel->setText(QString::number(year));
        connect(mUi->yearLabel, &CalendarLabel::leftClicked,
                this, &CalendarWidget::goToYear);
    }
    else
    {
        year = QDate::currentDate().year();
    }

    setMonthName(month);
    mUi->monthLabel->setSelectable(true);
    connect(mUi->monthLabel, &CalendarLabel::leftClicked,
            this, &CalendarWidget::goToMonth);

    int currentDay = 1;
    QDate date(year, month, 1);
    int i = date.dayOfWeek();
    int size = date.daysInMonth();
    int currentRow = 1;
    QVector <CalendarLabel *> week;
    for( ; currentDay <= size; ++currentDay)
    {       
        CalendarLabel *day = new CalendarLabel(QString::number(currentDay));
        day->setSelectable(true);
        connect(day, &CalendarLabel::leftClicked,
                this, &CalendarWidget::goToDay);

        week.push_back(day);
        mUi->bodyLayout->addWidget(day, currentRow, i);
        ++i;
        if(i > DAYS_IN_WEEK)
        {
            mDaysVector.insert(currentRow, week);
            week.clear();
            i = 1;
            ++currentRow;
        }
    }
    if(!week.isEmpty())
    {
        mDaysVector.insert(currentRow, week);
        week.clear();
    }
    mWeeksAmount = currentRow;
    formWeeksContainer(mWeeksAmount);
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

void CalendarWidget::formWeeksContainer(int size)
{
    mWeeksVector.push_back(mUi->week1Label);
    mWeeksVector.push_back(mUi->week2Label);
    mWeeksVector.push_back(mUi->week3Label);
    mWeeksVector.push_back(mUi->week4Label);
    mWeeksVector.push_back(mUi->week5Label);
    mWeeksVector.push_back(mUi->week6Label);
    connectWeeks(size);
}

void CalendarWidget::connectWeeks(int size)
{
    for(int i = 0; i < size; ++i)
    {
        mWeeksVector.at(i)->setSelectable(true);
        connect(mWeeksVector.at(i), &CalendarLabel::leftClicked,
                this, &CalendarWidget::goToWeek);
        connect (mWeeksVector.at(i),  &CalendarLabel::hoverEnter,
                this, QOverload<>::of(&CalendarWidget::selectWeek));
        connect(mWeeksVector.at(i), &CalendarLabel::hoverLeave,
                this, &CalendarWidget::unselectWeek);
    }
}

void CalendarWidget::paintEvent(QPaintEvent *event)
{
    Q_ASSERT(event);
    QPainter p(this);
    if(mWeekSelect)
    {
        p.setBrush(QColor("#74b5f2"));
        p.setPen(QColor("#74b5f2"));
    }
    else
    {
        p.setBrush(Qt::transparent);
        p.setPen(Qt::transparent);
    }
    p.drawRect(mCurrentWeekPos.x(), mCurrentWeekPos.y(),
               this->width(), mUi->week1Label->height());
    this->update();
}

