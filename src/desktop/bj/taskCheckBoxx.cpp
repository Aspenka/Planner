#include "taskCheckBox.h"
#include "ui_taskCheckBox.h"

TaskCheckBox::TaskCheckBox(const QString &title, QWidget *parent) :
    QWidget(parent), mUi(new Ui::TaskCheckBox)
{
    mUi->setupUi(this);
    mUi->titleLabel->setText(title);
}

TaskCheckBox::~TaskCheckBox()
{
    delete mUi;
}
