#ifndef TEMPERATURE_FORM_H
#define TEMPERATURE_FORM_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <temp_moniter_style1.h>
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
    void tempinit(temp_moniter_style1 *tempdata,int number);
    ~Temperature_Form();



private:
    Ui::Temperature_Form *ui;
};

#endif // TEMPERATURE_FORM_H
