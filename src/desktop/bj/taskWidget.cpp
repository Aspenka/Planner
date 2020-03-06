#include "taskWidget.h"
#include "ui_taskWidget.h"
#include <QMouseEvent>

TaskWidget::TaskWidget(QWidget *parent) :
    QWidget(parent), mUi(new Ui::TaskWidget),
    mAddTitleWidget(nullptr)
{
    mUi->setupUi(this);
    connect(mUi->addButton, &QPushButton::clicked,
            this, &TaskWidget::createNewTask);
    this->setMouseTracking(true);
}

TaskWidget::~TaskWidget()
{
    delete mUi;
    if(mAddTitleWidget != nullptr)
    {
        delete mAddTitleWidget;
    }
    if(!mTaskVector.isEmpty())
    {
        qDeleteAll(mTaskVector);
        mTaskVector.clear();
    }
}

void TaskWidget::addTitle(const QString &title)
{
    mTitle = title;
    mUi->titleLabel->setText(mTitle);
}

void TaskWidget::removeTask(TaskCheckBox *task)
{
    Q_UNUSED(task)
}

void TaskWidget::addTask(const QString &title)
{
    if(mAddTitleWidget != nullptr)
    {
        TaskCheckBox *checkBox = new TaskCheckBox(title);
        mTaskVector.push_back(checkBox);

        delete mAddTitleWidget;
        mAddTitleWidget = nullptr;

        mUi->taskLayout->insertWidget(mTaskVector.size(), checkBox);
    }
}

void TaskWidget::createNewTask()
{
    mAddTitleWidget = new AddTextWidget();
    connect(mAddTitleWidget, &AddTextWidget::sendTitle,
            this, &TaskWidget::addTask);
    mUi->taskLayout->insertWidget(mTaskVector.size() + 1, mAddTitleWidget);
    mAddTitleWidget->setFocus();
}

void TaskWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        if(mAddTitleWidget != nullptr)
        {
            delete mAddTitleWidget;
            mAddTitleWidget = nullptr;
        }
    }
}
