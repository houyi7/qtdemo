#ifndef TEACHER_H
#define TEACHER_H

#include <QMainWindow>
#include <QTableView>
#include <QMainWindow>
#include<QLineEdit>
#include<QString>
#include<QComboBox>
#include "coursestart.h"
namespace Ui {
class teacher;
}

class teacher : public QMainWindow
{
    Q_OBJECT

public:
    explicit teacher(QString,QWidget *parent = 0);
    ~teacher();
    QLineEdit*l1;
    QLineEdit*l2;
    QString tpyname;
    QTableView*tableView;
    coursestart*course1;
    QString myid;
    void quicksql(QString);
    QString send;
public slots:
    void btn_send_clicked(); //学生按钮按下后触发的事件
   void btn_get_clicked(); // 教师按钮按下后触发的事件
   void btn_opc_clicked(); // 教师按钮按下后触发的事件
   void ref();
private:
    Ui::teacher *ui;
};

#endif // TEACHER_H
