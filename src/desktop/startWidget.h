#ifndef STARTWIDGET_H
#define STARTWIDGET_H

#include <QWidget>

namespace Ui {
class StartWidget;
}

class StartWidget : public QWidget
{
    Q_OBJECT

public:
    explicit StartWidget(QWidget *parent = nullptr);
    ~StartWidget();

signals:
    void    openPlanner     ();
    void    openKakebo      ();
    void    openCollections ();

private:
    Ui::StartWidget *mUi;
};

#endif // STARTWIDGET_H
