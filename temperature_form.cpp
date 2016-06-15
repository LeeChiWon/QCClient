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
    QSqlQuery localquery(LocalDB);

    localquery.exec("select current_macine_name from systemset");
    localquery.next();
    current_machinename = localquery.value("current_macine_name").toString();

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
    mainloop.setInterval(LOOPTIME);
    connect(&mainloop,SIGNAL(timeout()),this,SLOT(mainlooptimeout()));
    mainloop.start();
}

void Temperature_Form::tempinit(temp_moniter_style1 *tempdata, int number){
    QSqlQuery remotequery(RemoteDB);
    QString querystr = QString ("select * from temp_table where machine_name = \'%1\'")
            .arg(current_machinename);
    remotequery.exec(querystr);
    remotequery.next();
    if(tempdata->ui->templist->count()==0){
        for(int i=1;i<=21;i++){
            QString temp_str = QString("temp%1_name").arg(i);
            tempdata->ui->templist->addItem(QIcon(":/Image/Image/Temperature.png"),remotequery.value(temp_str).toString());
        }
    }else {
        for(int i=1;i<=21;i++){
            QString temp_str = QString("temp%1_name").arg(i);
            tempdata->ui->templist->setItemText(i-1,remotequery.value(temp_str).toString());
        }

    }
    tempdata->number = number;
}
void Temperature_Form::mainlooptimeout(){
    QSqlQuery localquery(LocalDB);
    localquery.exec("select current_macine_name from systemset");
    localquery.next();
    //현재 가지고 있는 기계이름이 최신 으로 업데이트된 기계이름과 다르면
    if(current_machinename.compare(localquery.value("current_macine_name").toString())!=0){
        current_machinename = localquery.value("current_macine_name").toString();
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
    tempdataup(ui->temp1);
    tempdataup(ui->temp2);
    tempdataup(ui->temp3);
    tempdataup(ui->temp4);
    tempdataup(ui->temp5);
    tempdataup(ui->temp6);
    tempdataup(ui->temp7);
    tempdataup(ui->temp8);
    tempdataup(ui->temp9);
    tempdataup(ui->temp10);
    tempdataup(ui->temp11);
    tempdataup(ui->temp12);
    tempdataup(ui->temp13);
    tempdataup(ui->temp14);
    tempdataup(ui->temp15);

}
void Temperature_Form::tempdataup(temp_moniter_style1 *tempdata){

    QString temp_set_name = QString("temp%1_set").arg(tempdata->ui->templist->currentIndex()+1);
    QString temp_up_name = QString("temp%1_up").arg(tempdata->ui->templist->currentIndex()+1);
    QString temp_down_name = QString("temp%1_down").arg(tempdata->ui->templist->currentIndex()+1);
    QString temp_real_name = QString("temp%1_real").arg(tempdata->ui->templist->currentIndex()+1);
    QSqlQuery remotequery(RemoteDB);

    QString query = QString("select %1,%2,%3,%4 from temp_table where machine_name = \'%5\'")
                                .arg(temp_set_name)
                                .arg(temp_up_name)
                                .arg(temp_down_name)
                                .arg(temp_real_name)
                                .arg(current_machinename);
    remotequery.exec(query);
    remotequery.next();
    tempdata->ui->real_lcd_number->display(remotequery.value(temp_real_name).toDouble()/10.0);
    int real_value = remotequery.value(temp_real_name).toInt()/10;
    int setting_value = remotequery.value(temp_set_name).toInt()/10;
    int up_value =  remotequery.value(temp_up_name).toInt()/10;
    int down_value =  remotequery.value(temp_down_name).toInt()/10;
    up_value = setting_value + up_value;
    down_value = setting_value-down_value;
    tempdata->ui->setting_btn->setText(QString("%1").arg(setting_value));
    tempdata->ui->up_btn->setText(QString("%1").arg(up_value));
    tempdata->ui->down_btn->setText(QString("%1").arg(down_value));
    tempdata->ui->tempSlider->setMinimum(down_value);
    tempdata->ui->tempSlider->setMaximum(up_value);
    tempdata->ui->tempSlider->setValue(real_value);
}


Temperature_Form::~Temperature_Form()
{
    delete ui;
}
