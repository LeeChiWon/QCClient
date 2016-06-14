#include "configration_form.h"
#include "ui_configration_form.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

extern MainWindow *pMain;

Configration_Form::Configration_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Configration_Form)
{
    ui->setupUi(this);
    Init();
}

Configration_Form::~Configration_Form()
{
    delete ui;
}

void Configration_Form::resizeEvent(QResizeEvent *)
{
    /*화면크기에 따른 폰트사이즈 조정*/
    QFont font;
    font.setPointSizeF(this->width()/40);
    if(font.pointSizeF()<=12)
    {
        font.setPointSizeF(12);
    }
    ui->label_Title->setFont(font);
}

void Configration_Form::Init() //초기화
{
    DatabaseSettingMode(DB_INIT);
}

void Configration_Form::DatabaseSettingMode(int Mode)
{    
    switch(Mode)
    {
    case DB_INIT:
        DatabaseSettingInit();
        break;
    case DB_SAVE:
        DatabaseSettingSave();
        break;
    case DB_LOAD:
        break;
    }    
}

void Configration_Form::DatabaseSettingInit()
{
    QSqlDatabase LocalDB=QSqlDatabase::database("LocalDB");
    QSqlQuery query(LocalDB);
    query.exec("CREATE TABLE  IF NOT EXISTS systemset (remotedbip TEXT,"
               "remotedbport TEXT,"
               "remotedbname TEXT,"
               "version INTEGER,"
               "remotedbusername TEXT,"
               "remotedbpassword TEXT,"
               "current_macine_name TEXT"
               ");");
    query.exec("insert into systemset(remotedbip,"
                    "remotedbport,"
                    "remotedbname,"
                    "version,"
                    "remotedbusername,"
                    "remotedbpassword,"
                    "current_macine_name) "
                    "select \'127.0.0.1\',"
                    "\'3306\',"
                    "\'QCproject\',"
                    "1,"
                    "\'QCmen\',"
                    "\'1234\', "
                    "\'select\'"
                    "where not exists(select * from systemset);");
    query.exec("CREATE TABLE IF NOT EXISTS [temp_setindex]("
                    "[ID] INT NOT NULL DEFAULT 1, "
                    "[temp1] INT NOT NULL DEFAULT 0, "
                    "[temp2] INT NOT NULL DEFAULT 0, "
                    "[temp3] INT NOT NULL DEFAULT 0, "
                    "[temp4] INT NOT NULL DEFAULT 0, "
                    "[temp5] INT NOT NULL DEFAULT 0, "
                    "[temp6] INT NOT NULL DEFAULT 0, "
                    "[temp7] INT NOT NULL DEFAULT 0, "
                    "[temp8] INT NOT NULL DEFAULT 0, "
                    "[temp9] INT NOT NULL DEFAULT 0, "
                    "[temp10] INT NOT NULL DEFAULT 0, "
                    "[temp11] INT NOT NULL DEFAULT 0, "
                    "[temp12] INT NOT NULL DEFAULT 0, "
                    "[temp13] INT NOT NULL DEFAULT 0, "
                    "[temp14] INT NOT NULL DEFAULT 0, "
                    "[temp15] INT NOT NULL DEFAULT 0);"
                );
    query.exec("insert into temp_setindex(temp1) select 0 where not exists(select * from temp_setindex);");
}

void Configration_Form::DatabaseSettingSave()
{
    QSqlDatabase LocalDB=QSqlDatabase::database("LocalDB");
    QSqlQuery query(LocalDB);
    query.exec(QString("update systemset set remotedbip='%1',remotedbport='%2',version=1,remotedbusername='%3',remotedbpassword='%4'")
               .arg(ui->lineEdit_IPAddress->text(),ui->lineEdit_Port->text(),ui->lineEdit_UserName->text(),ui->lineEdit_Password->text()));
}

void Configration_Form::on_pushButton_Check_clicked()
{
    if(ui->lineEdit_IPAddress->text().isEmpty() || ui->lineEdit_Port->text().isEmpty() || ui->lineEdit_UserName->text().isEmpty()
            || ui->lineEdit_DBName->text().isEmpty()|| ui->lineEdit_Password->text().isEmpty())
    {        
        DatabaseSettingMode(DB_SAVE);
        QMessageBox::information(this,tr("Apply"),tr("Configration Applied."),QMessageBox::Ok);
    }
    else
    {
        QMessageBox::warning(this,tr("Warning"),tr("Configration is empty."),QMessageBox::Ok);
    }
    pMain->ui->mdiArea->closeActiveSubWindow();
}

void Configration_Form::on_pushButton_Apply_clicked()
{
    if(ui->lineEdit_IPAddress->text().isEmpty() || ui->lineEdit_Port->text().isEmpty() || ui->lineEdit_UserName->text().isEmpty()
            || ui->lineEdit_DBName->text().isEmpty()|| ui->lineEdit_Password->text().isEmpty())
    {
        DatabaseSettingMode(DB_SAVE);
        QMessageBox::information(this,tr("Apply"),tr("Configration Applied."),QMessageBox::Ok);
    }
    else
    {
        QMessageBox::warning(this,tr("Warning"),tr("Configration is empty."),QMessageBox::Ok);
    }
}

void Configration_Form::on_pushButton_Cancel_clicked()
{
    QMessageBox::information(this,tr("Cancel"),tr("Configration Canceled."),QMessageBox::Ok);
    pMain->ui->mdiArea->closeActiveSubWindow();
}
