#include "workplan_form.h"
#include "ui_workplan_form.h"

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

    connect(ui->comboBox_MachineName,SIGNAL(currentIndexChanged(QString)),this,SLOT(on_comboBox_MachineName_currentIndexChanged(QString)));
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
    localquery.exec(query);
}
