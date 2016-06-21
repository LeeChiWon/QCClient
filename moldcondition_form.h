#ifndef MOLDCONDITION_FORM_H
#define MOLDCONDITION_FORM_H

#include <QWidget>
#include <QtWidgets>
#include <QSqlDatabase>
#include <QSqlQuery>
//#include "ui_configration_form.h"
#include "moldcondition_style.h"

namespace Ui {
class MoldCondition_Form;
}

class MoldCondition_Form : public QWidget
{
    Q_OBJECT

public:
    explicit MoldCondition_Form(QWidget *parent = 0);
    ~MoldCondition_Form();

    /********** 변수 **********/
    QSqlDatabase LocalDB;
    QSqlDatabase RemoteDB;

    /********** 함수 **********/
    void Init();
    void Show();
    void MoldConditionStyleInit(MoldCondition_Style *Style,int Number,bool Hide);

private slots:
    void on_pushButton_Refresh_clicked();
    void on_pushButton_Printer_clicked();

private:
    Ui::MoldCondition_Form *ui;
   // Ui::Configration_Form *ui1;
};

#endif // MOLDCONDITION_FORM_H
