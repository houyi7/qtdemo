#include "stucon.h"
#include "ui_stucon.h"
#include <QStandardItem>
#include "studig.h"
stucon::stucon(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::stucon)
{
    ui->setupUi(this);



    setFixedSize(1000, 500);

    // add tableview
    tableView = new QTableView(this);
    tableView->setFixedSize(1000, 400);
    tableView->setMinimumSize(700, 400);
    tableView->verticalHeader()->hide(); // hide row number

    tableModel = new QStandardItemModel(this);
    tableView->setModel(tableModel); // recommend to set model before detail settings

    // set columns
    QStringList columnTitles;
    columnTitles << "学号" << "姓名" << "班级"<<"操作";
    tableModel->setHorizontalHeaderLabels(columnTitles);

          int i=0;
           QSqlQuery query("select * from student");
         while(query.next())
         {
         QString v1 = query.value(0).toString();
         QString v2 = query.value(1).toString();
         QString v3 = query.value(2).toString();

         tableModel->setItem(i, 0, new QStandardItem(v1));
         tableModel->setItem(i, 1, new QStandardItem(v2));
         tableModel->setItem(i, 2, new QStandardItem(v3));

        QPushButton*btn1 = new QPushButton("编辑");
        btn1->setProperty("id", v1);
        connect(btn1, SIGNAL(clicked()), this, SLOT(ClickDownloadButton()));

        tableView->setIndexWidget(tableModel->index(tableModel->rowCount() - 1, 3), btn1);
        i++;

    }



}

stucon::~stucon()
{
    delete ui;
}
void stucon::ClickDownloadButton()
{
    QPushButton *btm = (QPushButton *)sender();
     this-> ind=btm->property("id").toString();
     studig*d1=new studig(ind);
     connect(d1,SIGNAL(myclose()),this,SLOT(RRR()));
     d1->show();
}


void stucon::ClickDownloadButton2()
{

}








void stucon::RRR()
{
    int i=0;
     QSqlQuery query("select * from student");
   while(query.next())
   {
   QString v1 = query.value(0).toString();
   QString v2 = query.value(1).toString();
   QString v3 = query.value(2).toString();

   tableModel->setItem(i, 0, new QStandardItem(v1));
   tableModel->setItem(i, 1, new QStandardItem(v2));
   tableModel->setItem(i, 2, new QStandardItem(v3));

  QPushButton*btn1 = new QPushButton("编辑");
  btn1->setProperty("id", i);
  connect(btn1, SIGNAL(clicked()), this, SLOT(ClickDownloadButton()));

  tableView->setIndexWidget(tableModel->index(tableModel->rowCount() - 1, 3), btn1);
  i++;

  }
}



