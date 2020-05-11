#include "plannerWidget.h"
#include "ui_plannerWidget.h"

PlannerWidget::PlannerWidget(QWidget *parent) : QWidget(parent),
    mUi(new Ui::PlannerWidget)
{
    mUi->setupUi(this);
    mUi->focusLineEdit->setCheckable(false);
    mUi->focusLineEdit->setRemovable(false);
    mUi->plansWidget->setTitle(tr("Планы"));
    mUi->goalsWidget->setTitle(tr("Цели"));

    connect(mUi->backButton, &QPushButton::clicked, this, &PlannerWidget::goBack);
    connect(mUi->collapseButton, &QPushButton::clicked, this, &PlannerWidget::collapse);
    connect(mUi->focusChBox, &QCheckBox::stateChanged, this, &PlannerWidget::setFocusWidgetVisible);
    connect(mUi->plansChBox, &QCheckBox::stateChanged, this, &PlannerWidget::setPlansWidgetVisible);
    connect(mUi->goalsChBox, &QCheckBox::stateChanged, this, &PlannerWidget::setGoalsWidgetVisible);
    connect(mUi->calendarChBox, &QCheckBox::stateChanged, this, &PlannerWidget::setCalendarWidgetVisible);
}

PlannerWidget::~PlannerWidget()
{
    delete mUi;
}

void PlannerWidget::collapse()
{
    if(mUi->collapseButton->isChecked())
    {
        mUi->viewFrame->setVisible(true);
        mUi->collapseButton->setText("<<");
    }
    else
    {
        mUi->viewFrame->setVisible(false);
        mUi->collapseButton->setText(">>");
    }

}

void PlannerWidget::setFocusWidgetVisible()
{
    mUi->focuseWidget->setVisible(mUi->focusChBox->isChecked());
}

void PlannerWidget::setPlansWidgetVisible()
{
    mUi->plansWidget->setVisible(mUi->plansChBox->isChecked());
}

void PlannerWidget::setGoalsWidgetVisible()
{
    mUi->goalsWidget->setVisible(mUi->goalsChBox->isChecked());
}

void PlannerWidget::setCalendarWidgetVisible()
{
    mUi->calendarWidget->setVisible(mUi->calendarChBox->isChecked());
}
