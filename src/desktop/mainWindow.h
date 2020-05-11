#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "startWidget.h"
#include "bj/yearWidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void    openPlanner     ();
    void    openKakebo      ();
    void    openCollections ();
    void    openStartWidget ();

private:
    Ui::MainWindow *mUi;
};

#endif // MAINWINDOW_H
