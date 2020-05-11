#ifndef ITEMWIDGET_H
#define ITEMWIDGET_H

#include <QWidget>

namespace Ui {
class ItemWidget;
}

class ItemWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ItemWidget(QWidget *parent = nullptr);
    ~ItemWidget();

    bool    isEmpty         ();
    void    setCheckable    (bool var);
    void    setRemovable    (bool var);

signals:
    void    checked     (bool flag);
    void    removed     ();
    void    edited      (const QString &text);

private slots:
    void    onCheckBox  ();
    void    lostFocus   ();
private:
    Ui::ItemWidget *mUi;

    void changeLinEditState     (bool);
    void mouseDoubleClickEvent  (QMouseEvent *event) override;
    void focusOutEvent          (QFocusEvent *event) override;
};

#endif // ITEMWIDGET_H
