#include "manager.h"
#include "ui_manager.h"
#include "stucon.h"
#include "teccon.h"
manager::manager(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::manager)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(btn_stu_clicked()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(btn_tea_clicked()));
}

manager::~manager()
{
    delete ui;
}
void manager::btn_stu_clicked()
{
    stucon*s=new stucon;
    s->show();
}

void manager::btn_tea_clicked()
{
    teccon*s=new teccon;
    s->show();
}
