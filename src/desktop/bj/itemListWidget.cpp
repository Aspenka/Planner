#include "itemListWidget.h"
#include "ui_itemListWidget.h"

ItemListWidget::ItemListWidget(QWidget *parent) : QWidget(parent),
    mUi(new Ui::ItemListWidget), mTitle("")
{
    mUi->setupUi(this);
    connect(mUi->addButton, &QPushButton::clicked, this, &ItemListWidget::addItem);
}

ItemListWidget::~ItemListWidget()
{
    delete mUi;
    if(!mItemList.isEmpty())
    {
        qDeleteAll(mItemList);
        mItemList.clear();
    }
}

void ItemListWidget::setTitle(const QString &title)
{
    mTitle = title;
    mUi->titleLabel->setText(mTitle);
}

void ItemListWidget::addItem()
{
    if((!mItemList.isEmpty() && !mItemList.last()->isEmpty()) || mItemList.isEmpty())
    {
        createItem();
    }
    else
    {
        QApplication::beep();
    }
}

void ItemListWidget::removeItem()
{
    ItemWidget *item = qobject_cast <ItemWidget *> (sender());
    if(item != nullptr)
    {
        int index = mItemList.indexOf(item);
        if(index >= 0)
        {
            delete item;
            mItemList.removeAt(index);
            this->adjustSize();
        }
    }
}

void ItemListWidget::createItem()
{
    ItemWidget *item = new ItemWidget;
    connect(item, &ItemWidget::removed, this, &ItemListWidget::removeItem);
    mItemList.append(item);
    mUi->verticalLayout->insertWidget(mUi->verticalLayout->count() - 1, item, 0, Qt::AlignTop);
    this->adjustSize();
}
