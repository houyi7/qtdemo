#ifndef TECCON_H
#define TECCON_H

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
class teccon;
}

class teccon : public QMainWindow
{
    Q_OBJECT

public:
    explicit teccon(QWidget *parent = 0);
    ~teccon();
    QTableView *tableView;
    QStandardItemModel *tableModel;
public slots:
   void btn_clicked();
private:
    Ui::teccon *ui;
};

#endif // TECCON_H
