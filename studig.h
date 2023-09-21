#ifndef STUDIG_H
#define STUDIG_H

#include <QMainWindow>

namespace Ui {
class studig;
}

class studig : public QMainWindow
{
    Q_OBJECT

public:
    explicit studig( QString id,QWidget *parent = 0);
    ~studig();
    QString ind;
    QString helper(int i);

public slots:
 void btn_clicked();
signals:
    void myclose();
//    void findperson();

private:
    Ui::studig *ui;
};

#endif // STUDIG_H
