#include "addTextWidget.h"
#include "ui_addTextWidget.h"

AddTextWidget::AddTextWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddTextWidget)
{
    ui->setupUi(this);
}

AddTextWidget::~AddTextWidget()
{
    delete ui;
}
