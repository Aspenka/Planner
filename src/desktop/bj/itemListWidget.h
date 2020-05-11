#ifndef ITEMLISTWIDGET_H
#define ITEMLISTWIDGET_H

#include <QWidget>
#include <QList>
#include "desktop/bj/itemWidget.h"

namespace Ui {
class ItemListWidget;
}

class ItemListWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ItemListWidget(QWidget *parent = nullptr);
    ~ItemListWidget();

public slots:
    void    setTitle    (const QString &title);

private slots:
    void    addItem     ();
    void    removeItem  ();

private:
    Ui::ItemListWidget  *mUi;
    QString             mTitle;
    QList <ItemWidget*> mItemList;

    void    createItem  ();
};

#endif // ITEMLISTWIDGET_H
