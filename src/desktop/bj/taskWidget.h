#ifndef TASKWIDGET_H
#define TASKWIDGET_H

#include <QWidget>
#include <QVector>
#include <QCheckBox>
#include <QString>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>
#include <QPair>

namespace Ui {
class TaskWidget;
}

//class AddTitleWidget: public QWidget
//{
//    Q_OBJECT

//public:
//    AddTitleWidget(QWidget *parent = nullptr);
//    ~AddTitleWidget() {}

//signals:
//    void    sendTitle   (const QString &title);
//public slots:

//private slots:
//    void    getTitle    ();

//private:
//    QHBoxLayout mLayout;
//    QLineEdit   mTitleEdit;
//    QPushButton mSaveButton;
//};

//class CheckWidget: public QWidget
//{
//    Q_OBJECT

//public:
//    CheckWidget(QString title, QWidget *parent);
//    ~CheckWidget() {}

//private:
//    QCheckBox   mCheckBox;
//    QLabel      mTitleLabel;
//    QHBoxLayout mLayout;
//    QHorizontalSpacer
//};

class TaskWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TaskWidget(QWidget *parent = nullptr);
    ~TaskWidget();

    void addTitle   (const QString &title);

signals:

public slots:
    void    removeTask  (QCheckBox *task);
    void    addTask     (const QString &title);

private slots:
    void    createNewTask   ();

private:

    Ui::TaskWidget *mUi;
    QString         mTitle;
//    AddTitleWidget *mAddTitleWidget;
//    QVector <QPair
//    <QLabel*,QCheckBox *>>   mTaskVector;

    void    mousePressEvent   (QMouseEvent *event) override;
    void    removeAddTaskSidget ();
};

#endif // TASKWIDGET_H
