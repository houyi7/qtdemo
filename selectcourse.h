#ifndef SELECTCOURSE_H
#define SELECTCOURSE_H

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
class selectcourse;
}

class selectcourse : public QMainWindow
{
    Q_OBJECT

public:

QStandardItemModel *tableModel;
    int cnt[100]={0};
    QPushButton*btn[100];
      QString myid ;
    explicit selectcourse(QString Myid,QWidget *parent = 0);
    ~selectcourse();
    void quicksql(QString);
public slots:
   void ClickDownloadButton();


private:
    Ui::selectcourse *ui;
};

#endif // SELECTCOURSE_H
