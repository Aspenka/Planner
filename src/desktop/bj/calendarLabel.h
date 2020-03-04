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

    void    setSelectable   (bool f);

signals:
    void    leftClicked     ();
    void    rightClicked    ();

    void    hoverEnter      ();
    void    hoverLeave      ();

public slots:
    void    selectLabel     ();
    void    unselectLabel   ();
    void    setBold         ();
    void    unsetBold       ();

private:
    void    mousePressEvent(QMouseEvent *ev) override;
    bool    event   (QEvent *event) override;

    bool    mSelectable;
    bool    mIsBold;
};

#endif // CALENDARLABEL_H
