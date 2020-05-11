#include <QMouseEvent>
#include <QKeyEvent>
#include <QDebug>
#include "itemWidget.h"
#include "ui_itemWidget.h"

ItemWidget::ItemWidget(QWidget *parent) : QWidget(parent),
    mUi(new Ui::ItemWidget)
{
    mUi->setupUi(this);
    mUi->lineEdit->setFocus();
    connect(mUi->removeButn, &QPushButton::clicked, this, &ItemWidget::removed);
    connect(mUi->checkBox, &QCheckBox::toggled, this, &ItemWidget::onCheckBox);
    connect(mUi->lineEdit, &QLineEdit::editingFinished, this, &ItemWidget::lostFocus);
}

ItemWidget::~ItemWidget()
{
    delete mUi;
}

bool ItemWidget::isEmpty()
{
    if(mUi->lineEdit->text().isEmpty())
    {
        return true;
    }
    return false;
}

void ItemWidget::setCheckable(bool var)
{
    mUi->checkBox->setVisible(var);
}

void ItemWidget::setRemovable(bool var)
{
    mUi->removeButn->setVisible(var);
}

void ItemWidget::onCheckBox()
{
    emit checked(mUi->checkBox->isChecked());
}

void ItemWidget::lostFocus()
{
    if(!isEmpty())
    {
        changeLinEditState(false);
    }
    else
    {
        QApplication::beep();
    }
}

void ItemWidget::changeLinEditState(bool flag)
{
    mUi->lineEdit->setEnabled(flag);
}

void ItemWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        changeLinEditState(true);
    }
}

void ItemWidget::focusOutEvent(QFocusEvent *event)
{
    event->accept();
    lostFocus();
}
