#include "addTextWidget.h"
#include "ui_addTextWidget.h"

AddTextWidget::AddTextWidget(QWidget *parent) :
    QWidget(parent),
    mUi(new Ui::AddTextWidget)
{
    mUi->setupUi(this);
    connect(mUi->addButton, &QPushButton::clicked,
            this, &AddTextWidget::onAddButton);
}

AddTextWidget::~AddTextWidget()
{
    delete mUi;
}

void AddTextWidget::setFocus()
{
    mUi->textEdit->setFocus();
}

void AddTextWidget::onAddButton()
{
    emit sendTitle(mUi->textEdit->text());
}
