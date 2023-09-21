#include "student.h"
#include "ui_student.h"
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
#include<QStringList>
#include <QSqlTableModel>
student::student(QString id,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::student)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(btn_get_clicked()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(btn_enter_clicked()));
    this->myid=id;
    QSqlQuery query;
    QString csql=QString("select * from student where sid='%1'")
            .arg(myid);
     query.exec(csql);
     QString name;
     if (query.next())
         {
             name=query.value(1).toString();
         }
    ui->label->setText("欢迎您"+name+"同学");

}

student::~student()
{
    delete ui;
}

void student::btn_get_clicked()
{

    QString res;

    for(int i=1;i<=20;i++)
    {
        qDebug()<<QString::number(i);
        if(helper(QString::number(i),2)=="---")continue;
        QSqlQuery query;
          QString csql=QString("select * from course where cid=%1")
                  .arg(QString::number(i));
            query.exec(csql);
          while (query.next())
              {
                  res+="您的"+query.value(1).toString()+"成绩为";
              }
          res+=(helper(QString::number(i),2)=="0"?"未出":helper(QString::number(i),2))+"\n";
    }
     QMessageBox::information(this, "success",res );
}
QString student::helper(QString str,int i)
{
      QSqlQuery query;    
      QString c="course_"+str;
      qDebug()<<myid;
        QString csql=QString("select * from %1 where sid='%2'")
                .arg(c).arg(myid);

        query.exec(csql);

        if (query.next())
            {
                return query.value(3).toString();
            }
        return "---";

}

void student::btn_enter_clicked()
{

    sc=new selectcourse(this->myid);

    sc->show();

}
