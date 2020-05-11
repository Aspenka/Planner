#include "mainWindow.h"
#include "ui_mainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
    mUi(new Ui::MainWindow)
{
    mUi->setupUi(this);
    openStartWidget();
    this->setWindowTitle("Planner");
}

MainWindow::~MainWindow()
{
    delete mUi;
}

void MainWindow::openPlanner()
{
    YearWidget *plannerWidget = new YearWidget;
//    connect(plannerWidget, &YearWidget::goBack,
//            this, &MainWindow::openStartWidget);
    this->setCentralWidget(plannerWidget);
}

void MainWindow::openKakebo()
{

}

void MainWindow::openCollections()
{

}

void MainWindow::openStartWidget()
{
    StartWidget *startWidget = new StartWidget;
    connect(startWidget, &StartWidget::openPlanner,
            this, &MainWindow::openPlanner);
    this->setCentralWidget(startWidget);
}
