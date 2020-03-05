#include "taskCheckBox.h"
#include "ui_taskCheckBox.h"

TaskCheckBox::TaskCheckBox(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TaskCheckBox)
{
    ui->setupUi(this);
}

TaskCheckBox::~TaskCheckBox()
{
    delete ui;
}
