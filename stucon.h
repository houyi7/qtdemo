#ifndef STUCON_H
#define STUCON_H

#include <QMainWindow>
#include<QTableView>
#include <QSqlError>
#include <QString>
#include<QPushButton>
#include <QSqlTableModel>
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
#include <QStandardItemModel>
#include <QPushButton>
#include <QSqlTableModel>
#include<QString>
namespace Ui {
class stucon;
}

class stucon : public QMainWindow
{
    Q_OBJECT

public:
    explicit stucon(QWidget *parent = 0);
    ~stucon();
    QString ind;
    QTableView *tableView;
    QStandardItemModel *tableModel;
public slots:
   void ClickDownloadButton();
     void ClickDownloadButton2();
//      void ref();
     void RRR();

private:
    Ui::stucon *ui;
};

#endif // STUCON_H
