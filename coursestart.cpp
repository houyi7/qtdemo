#include "coursestart.h"
#include "ui_coursestart.h"

coursestart::coursestart(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::coursestart)
{
    ui->setupUi(this);
    this->setFixedSize(500,600);

             c1=new QLineEdit(this);           QLabel*wec1=new QLabel("课程名称",this);
             c2=new QLineEdit(this);           QLabel*wec2=new QLabel("授课时间",this);
             c3=new QLineEdit(this);            QLabel*wec3=new QLabel("授课地点",this);
             c4=new QLineEdit(this);           QLabel*wec4=new QLabel("任课教师",this);
             c5=new QLineEdit(this);           QLabel*wec5=new QLabel("课程人数",this);
             c1->setGeometry(100,100,300,50);    wec1->setGeometry(20,100,70,50);
             c2->setGeometry(100,180,300,50);   wec2->setGeometry(20,180,70,50);
             c3->setGeometry(100,260,300,50);   wec3->setGeometry(20,260,70,50);
             c4->setGeometry(100,340,300,50);   wec4->setGeometry(20,340,70,50);
             c5->setGeometry(100,420,300,50);   wec5->setGeometry(20,420,70,50);
//             QString nname = c1->text();
//                QString ntime= c2->text();
//                QString nplace = c3->text();
//                QString nteacher = c4->text();
//                 QString nnumber = c5->text();

      connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(btn_clicked()));
}

coursestart::~coursestart()
{
    delete ui;
}
void coursestart::btn_clicked()
{
    //SELECT * FROM table_name ORDER BY col_name DASC LIMIT 1; # 降序，最后一条


    QSqlQuery query;
    QString ind;



           QString nname = c1->text();
           QString ntime= c2->text();
           QString nplace = c3->text();
           QString nteacher = c4->text();
           QString nnumber = c5->text();


 QString sql=QString("insert into course (cname,cteacher,ctime,cplace,ccap,cleft) values ('%1','%2','%3','%4',%5,0)")
         .arg(nname).arg(nteacher).arg(ntime).arg(nplace).arg(nnumber);
 if(query.exec(sql))
 {
     QMessageBox::information(this, "success", "开课成功");
 }



 QString csql=QString("SELECT * FROM course ORDER BY cid DESC LIMIT 1");
 query.exec(csql);
 if (query.next())
     {
         ind = query.value(0).toString();
     }
qDebug()<<ind;
  QString sql2=QString("create table %1(sid varchar(20),sname varchar(20),sclass varchar(20),sgrade int)")
    .arg("course_"+ind);
   query.exec(sql2);
   emit(myclose());
this->close();
}






