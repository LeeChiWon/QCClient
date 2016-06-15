#ifndef TEMPERATURE_FORM_H
#define TEMPERATURE_FORM_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <temp_moniter_style1.h>
#include <QTimer>
#define TEMPLOOPTIME 1500
namespace Ui {
class Temperature_Form;
}

class Temperature_Form : public QWidget
{
    Q_OBJECT

public:
    explicit Temperature_Form(QWidget *parent = 0);
    QSqlDatabase RemoteDB;
    QSqlDatabase LocalDB;
    QTimer mainloop; //온도값 업데이트를 위한 루프 타이머
    QString current_machinename;
    void tempinit(temp_moniter_style1 *tempdata,int number);
    void tempdataup(temp_moniter_style1 *tempdata);
    ~Temperature_Form();



private:
    Ui::Temperature_Form *ui;

private slots:
    void mainlooptimeout();

};

#endif // TEMPERATURE_FORM_H
