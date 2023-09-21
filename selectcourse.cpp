#include "selectcourse.h"
#include "ui_selectcourse.h"
#include <QStandardItem>
selectcourse::selectcourse(QString Myid,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::selectcourse)
{
    ui->setupUi(this);

        setFixedSize(1000, 800);
        this->myid=Myid;
        // add tableview
        QTableView *tableView = new QTableView(this);
        tableView->setFixedSize(1000, 800);
        tableView->setMinimumSize(700, 500);
        tableView->verticalHeader()->hide(); // hide row number

        tableModel = new QStandardItemModel(this);
        tableView->setModel(tableModel); // recommend to set model before detail settings

        // set columns
        QStringList columnTitles;
        columnTitles << "课程名称" << "授课教师" << "授课时间" << "授课地点"<<"课程容量"<<"已选人数"<<"是否选课";
        tableModel->setHorizontalHeaderLabels(columnTitles);

              int i=0;
               QSqlQuery query("select cname,cteacher,ctime,cplace,ccap,cleft from course");
             while(query.next())
             {
             QString v1 = query.value(0).toString();
             QString v2 = query.value(1).toString();
             QString v3 = query.value(2).toString();
             QString v4 = query.value(3).toString();
             QString v5 = query.value(4).toString();
             QString v6 = query.value(5).toString();
             tableModel->setItem(i, 0, new QStandardItem(v1));
             tableModel->setItem(i, 1, new QStandardItem(v2));
             tableModel->setItem(i, 2, new QStandardItem(v3));
             tableModel->setItem(i, 3, new QStandardItem(v4));
             tableModel->setItem(i, 4, new QStandardItem(v5));
             tableModel->setItem(i, 5, new QStandardItem(v6));
            // add button to the last column

      btn[i] = new QPushButton("选课");

             QString sql=QString("select*from %1 where sid='%2'").
                     arg("course_"+QString::number(i+1)).arg(Myid);
             QSqlQuery query2;
//              qDebug()<<sql;
             query2.exec(sql);
             if(query2.next()){
                btn[i]->setText("退选");
                cnt[i]=1;
                 }



            // set custom property
            btn[i]->setProperty("id", i); // set custom property
//            button->setProperty("name", QString("hello qt tablview %1").arg(i));
//            button->setProperty("status", "normal");

            // set click event
            connect(btn[i], SIGNAL(clicked()), this, SLOT(ClickDownloadButton()));

            // notice every time insert the button at the last line
            tableView->setIndexWidget(tableModel->index(tableModel->rowCount() - 1, 6), btn[i]);
            i++;
        }





}

selectcourse::~selectcourse()
{
    delete ui;
}
void selectcourse::ClickDownloadButton()
{
    QPushButton *btm = (QPushButton *)sender();
    QString ind=btm->property("id").toString();
//    qDebug()<<ind;
    int i=ind.toInt();
    cnt[i]++;

    if(cnt[i]%2==0)
    {
        QString sql=QString("update course set cleft=cleft-1 where cid='%1'")
                .arg(QString::number(i+1));
        QSqlQuery query(sql);
        query.exec();
         QString str=tableModel->data(tableModel->index(ind.toInt(),5)).toString();//第row行第3列的内容
         int st=str.toInt();
         QString s = QString::number(--st);
         tableModel->setItem(ind.toInt(), 5, new QStandardItem(s));
         btn[i]->setText("选课");
         QString sql2=QString("delete from %1 where sid='%2'")
                 .arg("course_"+QString::number(i+1)).arg(myid);
          quicksql(sql2);
         return;
    }
    QString smax=tableModel->data(tableModel->index(ind.toInt(),4)).toString();

    QString sql2=QString("update course set cleft=cleft+1 where cid='%1'").arg(QString::number(i+1));
    qDebug()<<sql2;
    QSqlQuery query(sql2);
    query.exec();
     QString str=tableModel->data(tableModel->index(ind.toInt(),5)).toString();//第row行第3列的内容
     int st=str.toInt();
     if(st==smax.toInt())
     {
         QMessageBox::information(this, "success", "课程人数已满");
         return;
     }
     QString s = QString::number(++st);
     tableModel->setItem(ind.toInt(), 5, new QStandardItem(s));
     QString sql=QString("insert into %1(sid,sname,sclass) select sid,sname,sclass from ").arg("course_"+QString::number(i+1))+
                QString( "student where student.sid='%1'")
             .arg(myid);
     qDebug()<<sql;
      quicksql(sql);
     btn[i]->setText("退选");
}
void selectcourse::quicksql(QString str)
{
    QString sql=QString(str);
    QSqlQuery query;
    query.exec(sql);
}
