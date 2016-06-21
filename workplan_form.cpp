#include "workplan_form.h"
#include "ui_workplan_form.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

extern MainWindow *pMain;

WorkPlan_Form::WorkPlan_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WorkPlan_Form)
{
    ui->setupUi(this);
    RemoteDB=QSqlDatabase::database("RemoteDB");
    LocalDB=QSqlDatabase::database("LocalDB");

    QSqlQuery remotequery(RemoteDB);
    QSqlQuery localquery(LocalDB);
    //disconnect 를 하지 않으면 초기화 하는동안 계속 해서 시그널을 주기 때문에 초기화 할때만 시그널 연결해제를 한다.
    disconnect(ui->comboBox_MachineName,SIGNAL(currentIndexChanged(QString)),this,SLOT(on_comboBox_MachineName_currentIndexChanged(QString)));

    remotequery.exec("select machine_name from Systeminfo");
    while(remotequery.next()){
        ui->comboBox_MachineName->addItem(remotequery.value("machine_name").toString());
    }

    localquery.exec("select current_macine_name from systemset");
    localquery.next();
    ui->comboBox_MachineName->setCurrentText(localquery.value("current_macine_name").toString());

    QString query = QString("update systemset set current_macine_name = \'%1\'").arg(ui->comboBox_MachineName->currentText());
    localquery.exec(query);

    connect(ui->comboBox_MachineName,SIGNAL(currentIndexChanged(QString)),this,SLOT(on_comboBox_MachineName_currentIndexChanged(QString)));

    timer.setInterval(WORKPLANLOOPTIME);
    connect(&timer,SIGNAL(timeout()),this,SLOT(main_update_loop()));
    timer.start();
    main_update_loop();

    connect(pMain,SIGNAL(Retranslator()),this,SLOT(Retranslator()));
    Retranslator();
}
void WorkPlan_Form::main_update_loop(){
    QString maichine_name;
    maichine_name = ui->comboBox_MachineName->currentText();
    ui->machine_name_btn->setText(maichine_name);
    QSqlQuery remotequery(RemoteDB);
    QString query = QString("select * from Systeminfo where machine_name = \'%1\'").arg(maichine_name);
    remotequery.exec(query);
    remotequery.next();
    ui->mold_name_edit->setText(remotequery.value("mold_name").toString());
    ui->worker_value_label->setText(remotequery.value("worker").toString());
    ui->item_code_value_label->setText(remotequery.value("item_code").toString());
    ui->item_name_value_label->setText(remotequery.value("item_name").toString());
    ui->cycletime_value_label->setText(remotequery.value("cycle_time").toString());
    ui->cabitycount_value_label->setText(remotequery.value("cabity").toString());
    ui->production_lcd_dispaly->display(remotequery.value("production_count").toInt());
    ui->object_lcd_dispaly->display(remotequery.value("object_count").toInt());
    QString achievemen_rate = QString("%1")
            .arg(remotequery.value("achievemen_rate").toDouble(),0,'f',1);//1자리만 표현하기 위
    ui->achievemen_rate_lcd_display->display(achievemen_rate.toDouble());
    int goodcount = remotequery.value("production_count").toInt() -  remotequery.value("poor_count").toInt();
    int poorcount = remotequery.value("poor_count").toInt();
    ui->good_count_lcd_display->display(goodcount);
    ui->poor_count_lcd_display->display(poorcount);
    ui->mode_label->setText(remotequery.value("run_mode").toString());
    ui->progressBar->setValue(remotequery.value("achievemen_rate").toInt());

    int object_count = remotequery.value("object_count").toInt();
    int production_count = remotequery.value("production_count").toInt();
    int remind_count = object_count-production_count;

    QTime temptime(0,0,0);
    QTime remind_time;

    int remotetimesec = remotequery.value("cycle_time").toTime().secsTo(temptime);
    remotetimesec = remotetimesec * -1; //QString으로 받으면 -값이 나와서 -1을 곱해줌
    int remind_time_sec =  remind_count * remotetimesec;
    remind_time = temptime.addSecs(remind_time_sec);
    ui->remindtime_value_label->setText(remind_time.toString("hh:mm:ss"));
}

void WorkPlan_Form::Retranslator()
{
    ui->retranslateUi(this);
}

void WorkPlan_Form::resizeEvent(QResizeEvent *){
    /*화면크기에 따른 폰트사이즈 조정*/
    QFont font;

//
    font.setPointSizeF(this->width()/25);
    if(font.pointSizeF()<=12)
    {
        font.setPointSizeF(12);
    }
    ui->mold_name_edit->setFont(font);
//
    font.setPointSizeF(this->width()/25);
    if(font.pointSizeF()<=12)
    {
        font.setPointSizeF(12);
    }
    ui->mode_label->setFont(font);
//
    font.setPointSizeF(this->width()/30);
    if(font.pointSizeF()<=12)
    {
         font.setPointSizeF(12);
    }
    ui->machine_name_btn->setFont(font);
//
    font.setPointSizeF(this->width()/40);
    if(font.pointSizeF()<=12)
    {
        font.setPointSizeF(12);
    }
    ui->progressBar->setFont(font);
//
    font.setPointSizeF(this->width()/50);
    if(font.pointSizeF()<=12)
    {
        font.setPointSizeF(12);
    }
    ui->production_label->setFont(font);
    ui->object_label->setFont(font);
    ui->achievemen_rate_label->setFont(font);
    ui->good_count_label->setFont(font);
    ui->poor_count_label->setFont(font);

    font.setPointSizeF(this->width()/100);
    if(font.pointSizeF()<=12)
    {
        font.setPointSizeF(12);
    }
    ui->item_name_label->setFont(font);
    ui->item_name_value_label->setFont(font);
    ui->item_code_label->setFont(font);
    ui->item_code_value_label->setFont(font);
    ui->worker_label->setFont(font);
    ui->worker_value_label->setFont(font);
    ui->worker_set_btn->setFont(font);
    ui->cycletime_label->setFont(font);
    ui->cycletime_value_label->setFont(font);
    ui->mold_label->setFont(font);
    ui->remindtime_label->setFont(font);
    ui->remindtime_value_label->setFont(font);
    ui->cabitycount_label->setFont(font);
    ui->cabitycount_value_label->setFont(font);
    ui->mold_set_btn->setFont(font);
}

WorkPlan_Form::~WorkPlan_Form()
{
    delete ui;
}

void WorkPlan_Form::on_comboBox_MachineName_currentIndexChanged(const QString &arg1)
{
    QSqlQuery localquery(LocalDB);
    QString query = QString("update systemset set current_macine_name = \'%1\'").arg(arg1);
    qDebug()<<query;
    localquery.exec(query);
}
