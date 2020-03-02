#ifndef CALENDARLABEL_H
#define CALENDARLABEL_H

#include <QLabel>
#include <QWidget>

class CalendarLabel : public QLabel
{
    Q_OBJECT
public:
    explicit CalendarLabel(QWidget *parent = nullptr);
    CalendarLabel(QString text = "", QWidget *parent = nullptr);

signals:
    void    leftClicked     ();
    void    rightClicked    ();

private:
    void mousePressEvent(QMouseEvent *ev) override;

};

#endif // CALENDARLABEL_H
