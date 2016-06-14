#include "temperature_form.h"
#include "ui_temperature_form.h"
#include "ui_temp_moniter_style1.h"


Temperature_Form::Temperature_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Temperature_Form)
{
    ui->setupUi(this);
    RemoteDB=QSqlDatabase::database("RemoteDB");
    LocalDB=QSqlDatabase::database("LocalDB");
    tempinit(ui->temp1,1);
    tempinit(ui->temp2,2);
    tempinit(ui->temp3,3);
    tempinit(ui->temp4,4);
    tempinit(ui->temp5,5);
    tempinit(ui->temp6,6);
    tempinit(ui->temp7,7);
    tempinit(ui->temp8,8);
    tempinit(ui->temp9,9);
    tempinit(ui->temp10,10);
    tempinit(ui->temp11,11);
    tempinit(ui->temp12,12);
    tempinit(ui->temp13,13);
    tempinit(ui->temp14,14);
    tempinit(ui->temp15,15);

}

void Temperature_Form::tempinit(temp_moniter_style1 *tempdata, int number){
    QSqlQuery localquery(LocalDB);
    QSqlQuery remotequery(RemoteDB);
    localquery.exec("select current_macine_name from systemset");
    localquery.next();
    QString current_machine = localquery.value("current_macine_name").toString();
    QString querystr = QString ("select * from temp_table where machine_name = \'%1\'")
            .arg(current_machine);
    remotequery.exec(querystr);
    remotequery.next();

    for(int i=1;i<=21;i++){
        QString temp_str = QString("temp%1_name").arg(i);
        tempdata->ui->templist->addItem(QIcon(":/Image/Image/Temperature.png"),remotequery.value(temp_str).toString());
    }
    tempdata->number = number;
}

Temperature_Form::~Temperature_Form()
{
    delete ui;
}
