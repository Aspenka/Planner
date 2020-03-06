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

    void    setFocus    ();

signals:
    void    sendTitle   (const QString &title);

private slots:
    void    onAddButton ();

private:
    Ui::AddTextWidget *mUi;
};

#endif // ADDTEXTWIDGET_H
