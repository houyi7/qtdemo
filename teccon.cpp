#include "teccon.h"
#include "ui_teccon.h"

teccon::teccon(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::teccon)
{
    ui->setupUi(this);

      connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(btn_clicked()));
    setFixedSize(1000, 800);

    // add tableview
    tableView = new QTableView(this);
    tableView->setFixedSize(600, 400);
    tableView->setMinimumSize(600, 400);
    tableView->verticalHeader()->hide(); // hide row number

    tableModel = new QStandardItemModel(this);
    tableView->setModel(tableModel); // recommend to set model before detail settings

    // set columns
    QStringList columnTitles;
    columnTitles << "教师姓名" << "姓名拼音" ;
    tableModel->setHorizontalHeaderLabels(columnTitles);

          int i=0;
           QSqlQuery query("select * from teacher");
         while(query.next())
         {
         QString v1 = query.value(0).toString();
         QString v2 = query.value(1).toString();


         tableModel->setItem(i, 0, new QStandardItem(v1));
         tableModel->setItem(i, 1, new QStandardItem(v2));
        i++;

    }
}

teccon::~teccon()
{
    delete ui;
}

void teccon::btn_clicked()
{
    QString s1=ui->lineEdit->text();
     QString s2=ui->lineEdit_2->text();
     QString sql=QString("insert into teacher (tname,tpyname) values('%1','%2')")
             .arg(s1).arg(s2);
     QSqlQuery query(sql);

   while(query.next())
   {

   }



   int i=0;
    QSqlQuery  query2("select * from teacher");
  while(query2.next())
  {
  QString v1 = query2.value(0).toString();
  QString v2 = query2.value(1).toString();


  tableModel->setItem(i, 0, new QStandardItem(v1));
  tableModel->setItem(i, 1, new QStandardItem(v2));
 i++;

}
}
