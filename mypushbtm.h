#ifndef MYPUSHBTM_H
#define MYPUSHBTM_H

#include <QDialog>

namespace Ui {
class mypushbtm;
}

class mypushbtm : public QDialog
{
    Q_OBJECT

public:
    explicit mypushbtm(QWidget *parent = 0);
    ~mypushbtm();
    int cnt=0;

public slots:

    void btn_clicked(); //重置按钮按下后触发的事件
private:
    Ui::mypushbtm *ui;
};

#endif // MYPUSHBTM_H
