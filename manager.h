#ifndef MANAGER_H
#define MANAGER_H

#include <QMainWindow>

namespace Ui {
class manager;
}

class manager : public QMainWindow
{
    Q_OBJECT

public:
    explicit manager(QWidget *parent = 0);
    ~manager();

public slots:
    void btn_stu_clicked(); //学生按钮按下后触发的事件
    void btn_tea_clicked(); // 教师按钮按下后触发的事件

private:
    Ui::manager *ui;
};

#endif // MANAGER_H
