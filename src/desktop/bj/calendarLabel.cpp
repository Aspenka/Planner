#include "calendarLabel.h"
#include <QMouseEvent>

CalendarLabel::CalendarLabel(QWidget *parent):
    QLabel(parent), mSelectable(false), mIsBold(false)
{
    this->setAttribute(Qt::WA_Hover);
    this->setTextInteractionFlags(Qt::TextSelectableByMouse);
    this->setMouseTracking(true);    
}

CalendarLabel::CalendarLabel(QString text, QWidget *parent):
    QLabel(text, parent), mSelectable(false), mIsBold(false)
{
    this->setAttribute(Qt::WA_Hover);
    this->setTextInteractionFlags(Qt::TextSelectableByMouse);
    this->setMouseTracking(true);
}

void CalendarLabel::setSelectable(bool f)
{
    if(f)
    {
        connect(this, &CalendarLabel::hoverEnter,
                this, &CalendarLabel::selectLabel);
        connect(this, &CalendarLabel::hoverLeave,
                this, &CalendarLabel::unselectLabel);
    }
    else
    {
        disconnect(this, &CalendarLabel::hoverEnter,
                this, &CalendarLabel::selectLabel);
        disconnect(this, &CalendarLabel::hoverLeave,
                this, &CalendarLabel::unselectLabel);
    }
}

void CalendarLabel::unselectLabel()
{
    setStyleSheet("");
    if(mIsBold)
    {
        setBold();
    }
}

void CalendarLabel::setBold()
{
    setStyleSheet("QLabel { font: bold; }");
    mIsBold = true;
}

void CalendarLabel::unsetBold()
{
    setStyleSheet("QLabel { font: normal; }");
    mIsBold = false;
}

void CalendarLabel::selectLabel()
{

    if(mIsBold)
    {
        setStyleSheet("QLabel { background-color : #74b5f2; "
                      "font: bold;}");
    }
    else
    {
        setStyleSheet("QLabel { background-color : #74b5f2; }");
    }
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

bool CalendarLabel::event(QEvent *event)
{
    switch (event->type())
    {
        case QEvent::HoverEnter:
        {
            emit hoverEnter();
            break;
        }
        case QEvent::HoverLeave:
        {
            emit hoverLeave();
            break;
        }
        default:
        {
            break;
        }
    }
    return QWidget::event(event);
}
