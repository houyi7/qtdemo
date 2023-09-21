#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<loginwidget.h>
#include<student.h>
#include<teacher.h>
#include<manager.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();



public slots:
    void btn_stud_clicked(); //学生按钮按下后触发的事件
    void btn_tech_clicked(); // 教师按钮按下后触发的事件
    void btn_mana_clicked(); // 教师按钮按下后触发的事件



private:
    Ui::MainWindow *ui;
    loginwidget * m_log;
    student * m_stud;
    teacher * m_tech;
    manager* m_mana;
};

#endif // MAINWINDOW_H
