#include "loginwidget.h"
#include "ui_loginwidget.h"
#include "QMessageBox"
#include<QPainter>
#include<QSqlQuery>
#include<QDebug>
#include "student.h"
#include "teacher.h"
#include "manager.h"
//QWidget *parent
loginwidget::loginwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::loginwidget)
{
  QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("127.0.0.1");  //此处测试了下，用127.0.0.1，和远程的192.168.137.131.都使用的是ODBC配置的数据源地址。所有此函数不起作用。
    db.setPort(3306);
    db.setDatabaseName("MySQL");
    db.setUserName("root");
    db.setPassword("saber214");
    bool ok = db.open();

        if(ok){
          qDebug()<< "连接成功";

        }
       ui->setupUi(this);
      // connect 3个信号槽
      // 触发重置按钮的信号槽连接
      connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(btn_regist_clicked()));
      connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(btn_clear_clicked()));
      // 触发登录按钮的信号槽连接
      connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(btn_login_clicked()));

       connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(btn_logout_clicked()));
       // 发出信号后关闭登录窗口的信号槽连接
      connect(this,SIGNAL(close_window()),this,SLOT(close()));
      QPixmap *pixmap = new QPixmap(":/微信图片_20230402213021.jpg");
      pixmap->scaled(ui->label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
      ui->label->setScaledContents(true);
      ui->label->setPixmap(*pixmap);
      this->setFixedSize(400,340);
      winstud=new student;

      winmana=new manager;
}


loginwidget::~loginwidget()
{
    delete ui;
}


void loginwidget::btn_login_clicked()
{
    QString thnum = ui->lineEdit_1->text();
    // 从输入框获取密码
    QString thpassword = ui->lineEdit_2->text();
   QString str;

if(cov==1)str = QString("select *from tb_user where idd = '%1' and psw = '%2'").arg(thnum).arg(thpassword);
if(cov==2)str = QString("select *from tb_user2 where idd = '%1' and psw = '%2'").arg(thnum).arg(thpassword);
if(cov==3)str = QString("select *from tb_user3 where idd = '%1' and psw = '%2'").arg(thnum).arg(thpassword);
    QSqlQuery query;
    query.exec(str);
    if(query.next())   //遍历数据库查找数据
        {
           btn_clear_clicked();
           close_window();
           login();
           if(cov==1){ winstud=new student(thnum);   winstud->show();}
           if(cov==2){wintech=new teacher(thnum);wintech->show();}
           if(cov==3){winmana->show();}
           return;
        }
    QMessageBox::information(this, "Warning","用户名或密码错误!");
    btn_clear_clicked();

}



void loginwidget::btn_logout_clicked()
{
    QString thnum = ui->lineEdit_1->text();
    // 从输入框获取密码
    QString thpassword = ui->lineEdit_2->text();
      QString str;
    if(cov==1)str = QString("delete from tb_user where idd = '%1' and psw='%2' ").arg(thnum).arg(thpassword);
    if(cov==2)str = QString("delete from tb_user2 where idd = '%1' and psw='%2' ").arg(thnum).arg(thpassword);
    if(cov==3)str = QString("delete from tb_user3 where idd = '%1' and psw='%2' ").arg(thnum).arg(thpassword);

    QSqlQuery query;
    query.exec(str);
    if(!query.next())
      {
                btn_clear_clicked();
                QMessageBox::information(this, "success", "您已成功注销");
                return;
      }

 //           btn_clear_clicked();
//           QMessageBox::information(this, "success", "f");//??????????

}



void loginwidget::btn_regist_clicked()
{
   QString thnum = ui->lineEdit_1->text();
    // 从输入框获取密码
    QString thpassword = ui->lineEdit_2->text();


    QSqlQuery My_Query;
    QString insert_db;
    if(cov==1)
    {
        insert_db = QString("select * from student where sid='%1'")
                   .arg(thnum);
        My_Query.exec(insert_db);
        if(!My_Query.next())
        {
        QMessageBox::information(this, "Warning","用户名错误!");
        btn_clear_clicked();
        return;
        }
        insert_db = QString("select * from tb_user where idd='%1'")
                   .arg(thnum);
        My_Query.exec(insert_db);

        if(My_Query.next())
        {
        QMessageBox::information(this, "Warning","您早已注册账号!");
        btn_clear_clicked();
        return;
        }
     }


    if(cov==2)
    {
        insert_db = QString("select * from teacher where tpyname='%1'")
                .arg(thnum);
     My_Query.exec(insert_db);
     if(!My_Query.next())
     {
     QMessageBox::information(this, "Warning","用户名错误!");
     btn_clear_clicked();
     return;
     }

     insert_db = QString("select * from tb_user2 where idd='%1'")
                .arg(thnum);
     My_Query.exec(insert_db);

     if(My_Query.next())
     {
     QMessageBox::information(this, "Warning","您早已注册账号!");
     btn_clear_clicked();
     return;
     }

     }
  //idd psw


   //账号合法的
      if(cov==1)insert_db = QString("insert into tb_user values('%1','%2')")
              .arg(thnum).arg(thpassword);
      if(cov==2)insert_db = QString("insert into tb_user2 values('%1','%2')")
              .arg(thnum).arg(thpassword);
      if(cov==3)insert_db = QString("insert into tb_user3 values('%1','%2')")
               .arg(thnum).arg(thpassword);

       if(My_Query.exec(insert_db))
          {
          QMessageBox::information(this, "success", "您已成功注册");
          }
}



void loginwidget::btn_clear_clicked()
{
    ui->lineEdit_1->clear();
    ui->lineEdit_2->clear();
}
