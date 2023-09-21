#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "loginwidget.h"
#include<QLabel>
#include<QFont>
#include<QPushButton>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    m_log=new loginwidget;
//    m_log->show();
//    connect(m_log,SIGNAL(login()),this,SLOT(show()));


    QLabel*wec=new QLabel(this);
    wec->setGeometry(120,50,270,80);
    wec->setText("请选择您的身份：");
    this->resize(QSize(500,800));

    //设置字体大小
    QFont siz;
    siz.setPointSize(14);

     wec->setFont(siz);

     QPushButton*btn_stud=new QPushButton("我是学生",this);
     QPushButton*btn_tech=new QPushButton("我是老师",this);
     QPushButton*btn_mana=new QPushButton("我是管理员",this);
     siz.setPointSize(16);
     btn_stud->setFont(siz);
     btn_tech->setFont(siz);
     btn_mana->setFont(siz);

     btn_stud->setIcon(QPixmap(":/respix/9644.png_860.png"));
     btn_stud->setIconSize(QSize(50,50));
     btn_tech->setIcon(QPixmap(":/respix/2187336_214505461082_2.jpg"));
     btn_tech->setIconSize(QSize(60,60));
     btn_mana->setIcon(QPixmap(":/respix/4a5503de7f3b91810b0c8f5645fb24cc.jpg"));
     btn_mana->setIconSize(QSize(60,60));

     btn_stud->setGeometry(150,150,200,150);
     btn_tech->setGeometry(150,300,200,150);
      btn_mana->setGeometry(150,450,200,150);


     connect(btn_stud,SIGNAL(clicked()),this,SLOT(btn_stud_clicked()));
     connect(btn_tech,SIGNAL(clicked()),this,SLOT(btn_tech_clicked()));
     connect(btn_mana,SIGNAL(clicked()),this,SLOT(btn_mana_clicked()));



}
void MainWindow::btn_stud_clicked()
{
    m_stud=new student("1");
    m_log=new loginwidget;
    m_log->cov=1;
    m_log->show();
//    this->close();
}



void MainWindow::btn_tech_clicked()
{
    m_tech=new teacher("34");
    m_log=new loginwidget;
    m_log->cov=2;
    m_log->show();
//    this->close();
}
void MainWindow::btn_mana_clicked()
{
    m_mana=new manager;
    m_log=new loginwidget;
    m_log->cov=3;
    m_log->show();
//    this->close();
}
MainWindow::~MainWindow()
{
    delete ui;
}
