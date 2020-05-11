#ifndef PLANNERWIDGET_H
#define PLANNERWIDGET_H

#include <QWidget>

namespace Ui {
class PlannerWidget;
}

class PlannerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PlannerWidget(QWidget *parent = nullptr);
    ~PlannerWidget();

signals:
    void    goBack  ();

private slots:
    void    collapse                ();
    void    setFocusWidgetVisible   ();
    void    setPlansWidgetVisible   ();
    void    setGoalsWidgetVisible   ();
    void    setCalendarWidgetVisible();
private:
    Ui::PlannerWidget *mUi;
};

#endif // PLANNERWIDGET_H
