#include "moldcondition_form.h"
#include "ui_moldcondition_form.h"

MoldCondition_Form::MoldCondition_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MoldCondition_Form)
  //  ui1(new Ui::Configration_Form)
{    
  /*  int i=1;
    switch(i)
    {
    case 0:
        ui->setupUi(this);
        break;
    default:
        ui1->setupUi(this);
        break;
    }*/

    ui->setupUi(this);
    Init();
}

MoldCondition_Form::~MoldCondition_Form()
{
    delete ui;
}

void MoldCondition_Form::Init()
{

}

void MoldCondition_Form::Show()
{
    RemoteDB=QSqlDatabase::database("RemoteDB");
    LocalDB=QSqlDatabase::database("LocalDB");
    QSqlQuery localquery(LocalDB);

    localquery.exec("select current_macine_name from systemset");
    localquery.next();
    ui->label_Title->setText(localquery.value("current_macine_name").toString());


}

void MoldCondition_Form::MoldConditionStyleInit(MoldCondition_Style *Style, int Number, bool Hide)
{

}

void MoldCondition_Form::on_pushButton_Refresh_clicked()
{

}

void MoldCondition_Form::on_pushButton_Printer_clicked()
{

}
