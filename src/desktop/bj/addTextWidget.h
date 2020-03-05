#ifndef ADDTEXTWIDGET_H
#define ADDTEXTWIDGET_H

#include <QWidget>

namespace Ui {
class AddTextWidget;
}

class AddTextWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AddTextWidget(QWidget *parent = nullptr);
    ~AddTextWidget();

private:
    Ui::AddTextWidget *ui;
};

#endif // ADDTEXTWIDGET_H
