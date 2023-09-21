#ifndef STUDENT_H
#define STUDENT_H
#include<QTableView>
#include <QSqlError>
#include <QString>
#include<QPushButton>
#include <QSqlTableModel>
#include <QMainWindow>
#include<QString>
#include<selectcourse.h>
namespace Ui {
class student;
}

class student : public QMainWindow
{
    Q_OBJECT

public:
    int num[100]={0};
   QString myid;
     explicit student(QString id="0",QWidget *parent = 0);
    ~student();
    QString helper(QString,int);
selectcourse*sc;
public slots:
    void btn_get_clicked(); //学生按钮按下后触发的事件
   void btn_enter_clicked(); // 教师按钮按下后触发的事件

private:
    Ui::student *ui;

};

#endif // STUDENT_H
