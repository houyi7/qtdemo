#include "teacher.h"
#include "ui_teacher.h"


#include<get_grade.h>
#include "teacher.h"
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

teacher::teacher(QString tid,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::teacher)
{
        ui->setupUi(this);
       //写输入部分
        this->setFixedSize(500,600);
        QLabel*wec=new QLabel(this);
        wec->setGeometry(20,20,100,50);
        wec->setText("请输入科目：");
       this->myid=tid;
        QString nmae;

        QString sql2=QString("select*from teacher where tpyname='%1'").arg(tid);
        QSqlQuery query2;
        query2.exec(sql2);
        while(query2.next()){nmae=query2.value(0).toString();}
        ui->label->setText("欢迎您"+nmae+"老师");
        QStringList strList;
        QString sql3=QString("select*from course where cteacher=(select tname from teacher where tpyname='%1')")
                .arg(myid);
        QSqlQuery query;
        query.exec(sql3);
        while(query.next())
        {
            QString t=query.value(1).toString();
            strList.append(t);
        }


        ui->comboBox->addItems(strList);



        ui->comboBox->setGeometry(20,70,150,50);

        QLabel*fil=new QLabel(this);
        fil->setGeometry(190,20,120,50);
        fil->setText("请输入文件路径：");
        l2=new QLineEdit(this);
        l2->setGeometry(190,70,180,50);

//        this->resize(QSize(500,500));
        QFont siz;
        siz.setPointSize(14);

         QPushButton*btn_send=new QPushButton("发布成绩",this);
         QPushButton*btn_back=new QPushButton("退出",this);
         QPushButton*btn_get=new QPushButton("查看成绩",this);
         siz.setPointSize(16);
         btn_send->setFont(siz);
         btn_get->setFont(siz);





         btn_send->setGeometry(150,150,150,100);
         btn_get->setGeometry(150,300,150,100);
         btn_back->setGeometry(this->width()-70,this->height()-70,50,50);
         connect(btn_send,SIGNAL(clicked()),this,SLOT(btn_send_clicked()));
         connect(btn_get,SIGNAL(clicked()),this,SLOT(btn_get_clicked()));



        QPushButton*opc=new QPushButton("开设课程",this);
        opc->setGeometry(this->width()/2-90,500,159,100);
        connect(opc,SIGNAL(clicked()),this,SLOT(btn_opc_clicked()));


        QString emp=ui->comboBox->currentText();

        QString mid=QString("select cid from course where cname='%1'").arg(emp);
        QString sql=QString(mid);
//        QSqlQuery query;
        query.exec(sql);
        QString ind;
        if(query.next())  ind=query.value(0).toString();
        this->send="course_"+ind;
        qDebug()<<send;
    }

teacher::~teacher()
{
    delete ui;
}
void teacher::btn_send_clicked()
{


    QString emp=ui->comboBox->currentText();

    QString mid=QString("select cid from course where cname='%1'").arg(emp);
    QString sql=QString(mid);
     QSqlQuery query;
     query.exec(sql);
    QString ind;
    if(query.next())  ind=query.value(0).toString();

    QString path = l2->text();
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::information(this, "failed", "无法找到此文件");
        return;
        }
    QTextStream in(&file);


    while (true)
    {
        QString line = in.readLine();

       if (line.isNull())break;
      QStringList parts = line.split(",");
//     QString ind=send;
//            QString sql = QString("insert into %1 (sid,sname,sclass) values('%2','%3','%4')")
//              .arg("course_"+ind).arg(parts[0]).arg(parts[1]).arg(parts[2]);
                QSqlQuery query;
//                query.exec(sql);
                sql = QString("update  %1 set sgrade=%2 where sid='%3'")
                        .arg("course_"+ind).arg(parts[3]).arg(parts[0]);
                qDebug()<<sql;
                 query.exec(sql);
    }
    file.close();
    QMessageBox::information(this, "success", "成绩表已发布成功");
}
void teacher::btn_get_clicked()
{

    QString emp=ui->comboBox->currentText();

    QString mid=QString("select cid from course where cname='%1'").arg(emp);
    QString sql=QString(mid);
//        QSqlQuery query;
     QSqlQuery query;
     query.exec(sql);
    QString ind;
    if(query.next())  ind=query.value(0).toString();
    this->send="course_"+ind;
    get_grade*mg=new get_grade(this->send);
    mg->show();
}
 void teacher::btn_opc_clicked()
 {
    course1=new coursestart;
    course1->show();
    //connect(btn_get,SIGNAL(clicked()),this,SLOT(btn_get_clicked()));
    connect(course1,SIGNAL(myclose()),this,SLOT(ref()));
 }
 void teacher::quicksql(QString str)
 {
     QString sql=QString(str);
     QSqlQuery query;
     query.exec(sql);

 }

 void teacher::ref()
 {
     QStringList strList2;
     QString sql3=QString("select*from course where cteacher=(select tname from teacher where tpyname='%1')")
             .arg(myid);
     QSqlQuery query;
     query.exec(sql3);
     while(query.next())
     {
         QString t=query.value(1).toString();
         strList2.append(t);
     }

    ui->comboBox->clear();
     ui->comboBox->addItems(strList2);



     ui->comboBox->setGeometry(20,70,150,50);
 }
