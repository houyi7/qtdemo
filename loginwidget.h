#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>
#include "student.h"
#include "teacher.h"
#include "manager.h"
namespace Ui {
class loginwidget;
}

class loginwidget : public QWidget
{
    Q_OBJECT

public:
    //QWidget *parent = 0
    int cov;
    explicit loginwidget(QWidget *parent = 0);
    ~loginwidget();
signals:
    void login(); //登录主界面信号
    void close_window(); //关闭登录界面信号


public slots:

    void btn_regist_clicked(); //重置按钮按下后触发的事件
    void btn_login_clicked(); //登录按钮按下后触发的事件
    void btn_logout_clicked(); //登录按钮按下后触发的事件
    void btn_clear_clicked();  //重置按钮按下后触发的事件


private:
    Ui::loginwidget *ui;
    student*winstud;
    teacher*wintech;
    manager*winmana;

};

#endif // LOGINWIDGET_H
