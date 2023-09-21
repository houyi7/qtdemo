#include "mypushbtm.h"
#include "ui_mypushbtm.h"

mypushbtm::mypushbtm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mypushbtm)
{
    ui->setupUi(this);
    connect(this,SIGNAL(clicked()),this,SLOT(btn_clicked()));
}

mypushbtm::~mypushbtm()
{
    delete ui;
}
void mypushbtm::btn_clicked()
{
    if(cnt%2==0)
    {
        this->settext
    }


}
