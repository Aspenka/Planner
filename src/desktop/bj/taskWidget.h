#ifndef TASKWIDGET_H
#define TASKWIDGET_H

#include <QWidget>
#include <QVector>
#include "addTextWidget.h"
#include "taskCheckBox.h"

namespace Ui {
class TaskWidget;
}

class TaskWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TaskWidget(QWidget *parent = nullptr);
    ~TaskWidget();

    void addTitle   (const QString &title);

signals:

public slots:
    void    removeTask  (TaskCheckBox *task);
    void    addTask     (const QString &title);

private slots:
    void    createNewTask   ();

private:

    Ui::TaskWidget *mUi;
    QString         mTitle;
    AddTextWidget   *mAddTitleWidget;
    QVector <TaskCheckBox *>   mTaskVector;

    void    mousePressEvent   (QMouseEvent *event) override;
};

#endif // TASKWIDGET_H
