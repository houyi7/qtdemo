#include "studig.h"
#include "ui_studig.h"
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
studig::studig(QString id,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::studig)
{
    ui->setupUi(this);
    this->ind=id;
      connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(btn_clicked()));


    ui->lineEdit->setText(helper(1));ui->lineEdit_2->setText(helper(0));
    ui->lineEdit_3->setText(helper(2));
}

studig::~studig()
{
    delete ui;
}


QString studig::helper(int i)
{
      QSqlQuery query;


        QString csql=QString("select * from student where sid=%1")
                .arg(ind);
        if(!query.exec(csql))
        {
              QMessageBox::information(this, "failed", "学号错误");

        }
        while (query.next())
            {
               return query.value(i).toString();
            }

}



void studig::btn_clicked()
{
    //    QSqlQuery query;
    //      QString csql=QString("select * from %1 where sid=%2")
    //              .arg(str).arg(myid);
    //      if(!query.exec(csql))
    //      {


    //      }


    QString s1=ui->lineEdit_2->text();
    QString s2=ui->lineEdit->text();
    QString s3=ui->lineEdit_3->text();
        QSqlQuery query;
          QString csql=QString("update student set sid='%1' ,sname='%2',sclass='%3' where sid='%4'")
                  .arg(s1).arg(s2).arg(s3).arg(s1);
          if(!query.exec(csql))
          {


          }
          this->close();
          emit(myclose());
}
