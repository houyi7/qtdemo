#include "get_grade.h"
#include "ui_get_grade.h"

get_grade::get_grade(QString s,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::get_grade)
{
    ui->setupUi(this);

    this->myid=s;
    mode= new QSqlQueryModel(ui->tableView);

   connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(btn_select_clicked()));
   connect(ui->tableView->horizontalHeader(), SIGNAL(sectionClicked(int)),
                   this, SLOT(onHeaderClicked(int)));
   connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(btn_change_clicked()));
    qDebug()<<s;
   QString sql = QString("select * from %1 ")
           .arg(s);
        mode->setQuery(sql);
        mode->setHeaderData(0,Qt::Horizontal,tr("学号"));
        mode->setHeaderData(1, Qt::Horizontal, tr("姓名"));
        mode->setHeaderData(2, Qt::Horizontal, tr("班别"));
        mode->setHeaderData(3, Qt::Horizontal, tr("成绩"));
        ui->tableView->horizontalHeader()->setSortIndicatorShown(true);		//显示排序图标（默认为上下箭头）


        ui->tableView->setModel(mode);

}

get_grade::~get_grade()
{
    delete ui;
}




void get_grade::onHeaderClicked(int c)
{
    QString sub=myid;
    QString sid=ui->lineEdit_2->text();
    QString sname=ui->lineEdit_3->text();
    QString sclass=ui->lineEdit_4->text();
    qDebug()<<sname<<sclass;
    QString sql ;
     sql = QString("select * from %1 where sid like '%2' and sname like '%3' and sclass like '%4'")
            .arg(sub).arg(sid+"%").arg("%"+sname+"%").arg("%"+sclass+"%");
    if(c==2) sql = QString("select * from %1 where sid like '%2' and sname like '%3' and sclass like '%4' ORDER BY sclass ASC")
            .arg(sub).arg(sid+"%").arg("%"+sname+"%").arg("%"+sclass+"%");
    if(c==3) sql = QString("select * from %1 where sid like '%2' and sname like '%3' and sclass like '%4' ORDER BY sgrade DESC")
            .arg(sub).arg(sid+"%").arg("%"+sname+"%").arg("%"+sclass+"%");

         mode->setQuery(sql);
         mode->setHeaderData(0,Qt::Horizontal,tr("学号"));
         mode->setHeaderData(1, Qt::Horizontal, tr("姓名"));
         mode->setHeaderData(2, Qt::Horizontal, tr("班别"));
         mode->setHeaderData(3, Qt::Horizontal, tr("成绩"));
         ui->tableView->horizontalHeader()->setSortIndicatorShown(true);		//显示排序图标（默认为上下箭头）


         ui->tableView->setModel(mode);
}


void get_grade::btn_select_clicked()
{
        QString sub=myid;
        QString sid=ui->lineEdit_2->text();
        QString sname=ui->lineEdit_3->text();
        QString sclass=ui->lineEdit_4->text();
        qDebug()<<sname<<sclass;
        QString sql ;
         sql = QString("select * from %1 where sid like '%2' and sname like '%3' and sclass like '%4'")
                .arg(sub).arg(sid+"%").arg("%"+sname+"%").arg("%"+sclass);

                mode->setQuery(sql);
         mode->setHeaderData(0,Qt::Horizontal,tr("学号"));
         mode->setHeaderData(1, Qt::Horizontal, tr("姓名"));
         mode->setHeaderData(2, Qt::Horizontal, tr("班别"));
         mode->setHeaderData(3, Qt::Horizontal, tr("成绩"));
         ui->tableView->horizontalHeader()->setSortIndicatorShown(true);		//显示排序图标（默认为上下箭头）
         ui->tableView->setModel(mode);



}
void get_grade::btn_change_clicked()
{
    QString sub=myid;
    QString sid=ui->lineEdit_2->text();
    QString sname=ui->lineEdit_3->text();
    QString sclass=ui->lineEdit_4->text();
    QString ng=ui->lineEdit_5->text();
    qDebug()<<ng;
    QString sql ;
    if(sid==""||sname==""||sclass==""||ng=="")QMessageBox::information(this, "success", "成绩表修改失败");
     sql = QString(" update %1 set sgrade=%2 where sid=%3 and sname ='%4' and sclass='%5'")
            .arg(sub).arg(ng).arg(sid).arg(sname).arg(sclass);
     if(sub==""||sid==""||sname==""||sclass==""||ng=="")
     {
         QMessageBox::information(this, "success", "所有数据都必须填写");
     }
     QSqlQuery query;
        if(query.exec(sql))
        {
            QMessageBox::information(this, "success", "成绩表已修改成功");
        }
        else
        {
             QMessageBox::information(this, "success", "成绩表修改失败");
        }
         sql = QString("select * from %1 ")
                .arg(myid);
             mode->setQuery(sql);
             mode->setHeaderData(0,Qt::Horizontal,tr("学号"));
             mode->setHeaderData(1, Qt::Horizontal, tr("姓名"));
             mode->setHeaderData(2, Qt::Horizontal, tr("班别"));
             mode->setHeaderData(3, Qt::Horizontal, tr("成绩"));
             ui->tableView->horizontalHeader()->setSortIndicatorShown(true);		//显示排序图标（默认为上下箭头）


             ui->tableView->setModel(mode);
}
