#include "calendarLabel.h"
#include <QMouseEvent>

CalendarLabel::CalendarLabel(QWidget *parent):
    QLabel(parent)
{

}

CalendarLabel::CalendarLabel(QString text, QWidget *parent):
    QLabel(text, parent)
{

}

void CalendarLabel::mousePressEvent(QMouseEvent *ev)
{
    if(ev->button() == Qt::LeftButton)
    {
        emit leftClicked();
    }
    if(ev->button() == Qt::RightButton)
    {
        emit rightClicked();
    }
}
