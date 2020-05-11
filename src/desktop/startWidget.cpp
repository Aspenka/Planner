#include "startWidget.h"
#include "ui_startwWdget.h"

StartWidget::StartWidget(QWidget *parent) :
    QWidget(parent),
    mUi(new Ui::StartWidget)
{
    mUi->setupUi(this);

    connect(mUi->plannerButton, &QPushButton::clicked,
            this, &StartWidget::openPlanner);
    connect(mUi->kakeboButton, &QPushButton::clicked,
            this, &StartWidget::openKakebo);
    connect(mUi->collectionButton, &QPushButton::clicked,
            this, &StartWidget::openCollections);
}

StartWidget::~StartWidget()
{
    delete mUi;
}
