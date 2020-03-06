#ifndef TASKCHECKBOX_H
#define TASKCHECKBOX_H

#include <QWidget>

namespace Ui {
class TaskCheckBox;
}

class TaskCheckBox : public QWidget
{
    Q_OBJECT

public:
    explicit TaskCheckBox(const QString &title, QWidget *parent = nullptr);
    ~TaskCheckBox();

private:
    Ui::TaskCheckBox *mUi;
};

#endif // TASKCHECKBOX_H
