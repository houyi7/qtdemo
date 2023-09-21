#ifndef COURSESTART_H
#define COURSESTART_H

#include <QMainWindow>
#include<QTableView>
#include <QSqlError>
#include <QString>
#include<QPushButton>
#include <QSqlTableModel>
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
#include <QStandardItemModel>
#include <QPushButton>
#include <QSqlTableModel>
#include<QString>
namespace Ui {
class coursestart;
}

class coursestart : public QMainWindow
{
    Q_OBJECT

public:
    explicit coursestart(QWidget *parent = 0);
      ~coursestart();
      QLineEdit*c1;
      QLineEdit*c2;
       QLineEdit*c3;
       QLineEdit*c4;
        QLineEdit*c5;

public slots:
    void btn_clicked(); //重置按钮按下后触发的事件
signals:
    void myclose();
private:
    Ui::coursestart *ui;
};

#endif // COURSESTART_H
