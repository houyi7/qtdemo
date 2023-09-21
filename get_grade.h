#ifndef GET_GRADE_H
#define GET_GRADE_H

#include <QMainWindow>
#include<QPushButton>
#include<QFont>
#include<QLabel>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QFile>
#include <iostream>
#include <QTextStream>
#include <QDebug>
#include<QLineEdit>
#include <QWidget>
#include <QSqlDatabase>
 #include<QTableView>
#include <QSqlError>
#include <QString>

#include <QSqlTableModel>
namespace Ui {
class get_grade;
}

class get_grade : public QMainWindow
{
    Q_OBJECT

public:
         QString myid;
        QSqlQueryModel *mode;
    explicit get_grade(QString s,QWidget *parent = 0);
    ~get_grade();

public slots:

    void onHeaderClicked(int c);
    void btn_select_clicked(); //重置按钮按下后触发的事件
    void btn_change_clicked(); //重置按钮按下后触发的事件
private:
    Ui::get_grade *ui;
};

#endif // GET_GRADE_H
