#include "taskWidget.h"
#include "ui_taskWidget.h"
#include <QMouseEvent>

TaskWidget::TaskWidget(QWidget *parent) :
    QWidget(parent), mUi(new Ui::TaskWidget)/*,
    mAddTitleWidget(nullptr)*/
{
    mUi->setupUi(this);
    connect(mUi->addButton, &QPushButton::clicked,
            this, &TaskWidget::createNewTask);
    this->setMouseTracking(true);
}

TaskWidget::~TaskWidget()
{
    delete mUi;
//    if(mAddTitleWidget != nullptr)
//    {
//        delete mAddTitleWidget;
//    }
//    if(!mTaskVector.isEmpty())
//    {
//        qDeleteAll(mTaskVector);
//        mTaskVector.clear();
//    }
}

void TaskWidget::addTitle(const QString &title)
{
    mTitle = title;
    mUi->titleLabel->setText(mTitle);
}

void TaskWidget::removeTask(QCheckBox *task)
{
    Q_UNUSED(task)
}

void TaskWidget::addTask(const QString &title)
{
//    AddTitleWidget *widget = static_cast<AddTitleWidget *>(sender());
//    if(widget != nullptr)
//    {
//        QCheckBox *task = new QCheckBox(title);
//        task->setLayoutDirection(Qt::RightToLeft);
//        mTaskVector.push_back(task);
//        mUi->taskLayout->insertWidget(mTaskVector.size(), task);
//        removeAddTaskSidget();
//    }
}

void TaskWidget::createNewTask()
{
//    if(mAddTitleWidget == nullptr)
//    {
//        mAddTitleWidget = new AddTitleWidget;
//        connect(mAddTitleWidget, &AddTitleWidget::sendTitle,
//                this, &TaskWidget::addTask);
//        mUi->taskLayout->insertWidget(mTaskVector.size() + 1, mAddTitleWidget);
//    }
}

void TaskWidget::mousePressEvent(QMouseEvent *event)
{
//     if(event->button() == Qt::LeftButton)
//     {
//         if(mAddTitleWidget != nullptr)
//         {
//            removeAddTaskSidget();
//         }
//     }
}

void TaskWidget::removeAddTaskSidget()
{
//    mUi->taskLayout->removeWidget(mAddTitleWidget);
//    mUi->taskLayout->update();
//    delete mAddTitleWidget;
//    mAddTitleWidget = nullptr;
}

//AddTitleWidget::AddTitleWidget(QWidget *parent): QWidget (parent),
//    mSaveButton(tr("Добавить"))
//{
//    connect(&mSaveButton, &QPushButton::clicked,
//            this, &AddTitleWidget::getTitle);
//    mLayout.addWidget(&mTitleEdit);
//    mLayout.addWidget(&mSaveButton);
//    this->setLayout(&mLayout);
//}

//void AddTitleWidget::getTitle()
//{
//    emit sendTitle(mTitleEdit.text());
//}
