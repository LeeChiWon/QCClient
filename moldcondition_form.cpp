#include "moldcondition_form.h"
#include "ui_moldcondition_form.h"
#include "ui_moldcondition_style.h"
#include "globalinclude.h"
#include "ui_moldcondition_style1.h"

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
    Mainloop.stop();
    InjWidgetStyle.clear();
    HoldPWidgetStyle.clear();
    ChgWidgetStyle.clear();
    SuckbWidgetStyle.clear();
    TempWidgetStyle.clear();
    delete ui;
}

void MoldCondition_Form::Init()
{
    Mainloop.setInterval(TIMEOUT);
    InjWidgetStyle.append(ui->widget_InjStep_1);
    InjWidgetStyle.append(ui->widget_InjStep_2);
    InjWidgetStyle.append(ui->widget_InjStep_3);
    InjWidgetStyle.append(ui->widget_InjStep_4);
    InjWidgetStyle.append(ui->widget_InjStep_5);
    InjWidgetStyle.append(ui->widget_InjStep_6);
    InjWidgetStyle.append(ui->widget_InjStep_7);
    InjWidgetStyle.append(ui->widget_InjStep_8);
    InjWidgetStyle.append(ui->widget_InjStep_9);
    InjWidgetStyle.append(ui->widget_InjStep_10);

    HoldPWidgetStyle.append(ui->widget_Hold_Step_1);
    HoldPWidgetStyle.append(ui->widget_Hold_Step_2);
    HoldPWidgetStyle.append(ui->widget_Hold_Step_3);
    HoldPWidgetStyle.append(ui->widget_Hold_Step_4);
    HoldPWidgetStyle.append(ui->widget_Hold_Step_5);

    ChgWidgetStyle.append(ui->widget_Chg_Step_1);
    ChgWidgetStyle.append(ui->widget_Chg_Step_2);
    ChgWidgetStyle.append(ui->widget_Chg_Step_3);

    SuckbWidgetStyle.append(ui->widget_Suckb1_Step);
    SuckbWidgetStyle.append(ui->widget_Suckb2_Step);

    TempWidgetStyle.append(ui->widget_Heater_Step_1);
    TempWidgetStyle.append(ui->widget_Heater_Step_2);
    TempWidgetStyle.append(ui->widget_Heater_Step_3);
    TempWidgetStyle.append(ui->widget_Heater_Step_4);
    TempWidgetStyle.append(ui->widget_Heater_Step_5);
    TempWidgetStyle.append(ui->widget_Heater_Step_6);
    TempWidgetStyle.append(ui->widget_Heater_Step_7);
    TempWidgetStyle.append(ui->widget_Heater_Step_8);
    TempWidgetStyle.append(ui->widget_ExternTemp_Step_1);
    TempWidgetStyle.append(ui->widget_ExternTemp_Step_2);
    TempWidgetStyle.append(ui->widget_ExternTemp_Step_3);
    TempWidgetStyle.append(ui->widget_ExternTemp_Step_4);
    TempWidgetStyle.append(ui->widget_ExternTemp_Step_5);
    TempWidgetStyle.append(ui->widget_ExternTemp_Step_6);
    TempWidgetStyle.append(ui->widget_ExternTemp_Step_7);
    TempWidgetStyle.append(ui->widget_ExternTemp_Step_8);

    RemoteDB=QSqlDatabase::database("RemoteDB");
    LocalDB=QSqlDatabase::database("LocalDB");

    connect(&Mainloop,SIGNAL(timeout()),this,SLOT(on_pushButton_Refresh_clicked()));
    Mainloop.start();
}

void MoldCondition_Form::Show()
{
    ui->label_DateTime->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));

    QSqlQuery localquery(LocalDB);
    localquery.exec("select current_macine_name from systemset");
    localquery.next();
    ui->label_Title->setText(localquery.value("current_macine_name").toString());

    QSqlQuery remotequery(RemoteDB);
    QStringList DbValue;

    remotequery.exec(QString("select * from Recipe_Info where machine_name='%1'").arg(ui->label_Title->text()));
    remotequery.next();

    for(int i=0; i<10; i++)
    {
        if(!DbValue.isEmpty())
        {
            DbValue.clear();
        }

        if(i<remotequery.value("injstep").toInt())
        {
            DbValue.append(QString("%1").arg(remotequery.value(QString("injspd_%1").arg(i+1)).toDouble(),0,'f',1));
            DbValue.append(QString("%1").arg(remotequery.value(QString("injprs_%1").arg(i+1)).toDouble(),0,'f',1));
            DbValue.append(QString("%1").arg(remotequery.value(QString("injpos_%1").arg(i+1)).toDouble(),0,'f',1));

            if(InjWidgetStyle.count()>0)
            {
                MoldConditionStyleInit(InjWidgetStyle.at(i),i,DbValue,false);
            }
        }
        else
        {
            MoldConditionStyleInit(InjWidgetStyle.at(i),i,DbValue,true);
        }

        if(i<5)
        {
            if(!DbValue.isEmpty())
            {
                DbValue.clear();
            }

            if(i<remotequery.value("holdstep").toInt())
            {
                DbValue.append(QString("%1").arg(remotequery.value(QString("holdspd_%1").arg(i+1)).toDouble(),0,'f',1));
                DbValue.append(QString("%1").arg(remotequery.value(QString("holdprs_%1").arg(i+1)).toDouble(),0,'f',1));
                DbValue.append(QString("%1").arg(remotequery.value(QString("holdtime_%1").arg(i+1)).toDouble(),0,'f',2));
                if(InjWidgetStyle.count()>0)
                {
                    MoldConditionStyleInit(HoldPWidgetStyle.at(i),i,DbValue,false);
                }
            }

            else
            {
                MoldConditionStyleInit(HoldPWidgetStyle.at(i),i,DbValue,true);
            }
        }

        if(i<3)
        {
            if(!DbValue.isEmpty())
            {
                DbValue.clear();
            }

            DbValue.append(QString("%1").arg(remotequery.value(QString("chgspd_%1").arg(i+1)).toDouble(),0,'f',1));
            DbValue.append(QString("%1").arg(remotequery.value(QString("chgbps_%1").arg(i+1)).toDouble(),0,'f',1));
            DbValue.append(QString("%1").arg(remotequery.value(QString("chgpos_%1").arg(i+1)).toDouble(),0,'f',1));

            if(ChgWidgetStyle.count()>0)
            {
                MoldConditionStyleInit(ChgWidgetStyle.at(i),i,DbValue,false);
            }
        }
        if(i<2)
        {
            if(!DbValue.isEmpty())
            {
                DbValue.clear();
            }

            DbValue.append(QString("%1").arg(remotequery.value(QString("suckbspd_%1").arg(i+1)).toDouble(),0,'f',1));
            DbValue.append(QString("%1").arg(remotequery.value(QString("suckbpos_%1").arg(i+1)).toDouble(),0,'f',1));

            if(ChgWidgetStyle.count()>0)
            {
                MoldConditionStyleInit(SuckbWidgetStyle.at(i),i,DbValue,false);
            }
        }
    }

    ui->lineEdit_SOVPos->setText(QString("%1").arg(remotequery.value(QString("sovpos")).toDouble(),0,'f',1));
    ui->lineEdit_SOVPrs->setText(QString("%1").arg(remotequery.value(QString("sovprs")).toDouble(),0,'f',1));
    ui->lineEdit_InjTime->setText(QString("%1").arg(remotequery.value(QString("injtime")).toDouble(),0,'f',2));
    ui->lineEdit_InjDelTime->setText(QString("%1").arg(remotequery.value(QString("injdeltime")).toDouble(),0,'f',2));
    ui->lineEdit_CoolTime->setText(QString("%1").arg(remotequery.value(QString("cooltime")).toDouble(),0,'f',2));
    ui->lineEdit_ChgDelTime->setText(QString("%1").arg(remotequery.value(QString("chgdeltime")).toDouble(),0,'f',2));

    remotequery.exec(QString("select * from temp_table where machine_name='%1'").arg(ui->label_Title->text()));
    remotequery.next();

    for(int i=0; i<8; i++)
    {
        if(!DbValue.isEmpty())
        {
            DbValue.clear();
        }

        DbValue.append(QString("%1").arg(remotequery.value(QString("Temp%1_name").arg(i+1)).toString()));
        DbValue.append(QString("%1").arg(remotequery.value(QString("Temp%1_set").arg(i+1)).toDouble(),0,'f',1));
        DbValue.append(QString("%1").arg(remotequery.value(QString("Temp%1_real").arg(i+1)).toDouble(),0,'f',1));

        if(remotequery.value(QString("Temp%1_onoff").arg(i+1)).toInt()==ON)
        {
            MoldConditionStyle1Init(TempWidgetStyle.at(i),DbValue,false);
        }
        else
        {
            MoldConditionStyle1Init(TempWidgetStyle.at(i),DbValue,true);
        }

        if(!DbValue.isEmpty())
        {
            DbValue.clear();
        }

        DbValue.append(QString("%1").arg(remotequery.value(QString("Temp%1_name").arg(i+9)).toString()));
        DbValue.append(QString("%1").arg(remotequery.value(QString("Temp%1_set").arg(i+9)).toDouble(),0,'f',1));
        DbValue.append(QString("%1").arg(remotequery.value(QString("Temp%1_real").arg(i+9)).toDouble(),0,'f',1));

        if(remotequery.value(QString("Temp%1_onoff").arg(i+9)).toInt()==ON)
        {
            MoldConditionStyle1Init(TempWidgetStyle.at(i+8),DbValue,false);
        }
        else
        {
            MoldConditionStyle1Init(TempWidgetStyle.at(i+8),DbValue,true);
        }
    }
}

void MoldCondition_Form::MoldConditionStyle1Init(MoldCondition_Style1 *Style, QStringList Data, bool Hide)
{
    Style->setEnabled(true);
    Style->ui->label_Title->setText("");
    Style->ui->lineEdit_1->setText("");
    Style->ui->lineEdit_2->setText("");

    if(Hide)
    {
        Style->setEnabled(false);
        return;
    }

    if(Data.count()>2)
    {
        Style->ui->label_Title->setText(Data.at(0));
        Style->ui->lineEdit_1->setText(Data.at(1));
        Style->ui->lineEdit_2->setText(Data.at(2));
    }
}

void MoldCondition_Form::MoldConditionStyleInit(MoldCondition_Style *Style, int Number, QStringList Data, bool Hide)
{
    Style->setEnabled(true);
    Style->ui->label_Title->setText("");
    Style->ui->lineEdit_1->setText("");
    Style->ui->lineEdit_2->setText("");
    Style->ui->lineEdit_3->setText("");

    if(Hide)
    {
        Style->setEnabled(false);
        return;
    }

    if(Data.count()>2)
    {
        QStringList Title;
        Title<<tr("1st")<<tr("2nd")<<tr("3rd")<<tr("4th")<<tr("5th")<<tr("6th")<<tr("7th")<<tr("8th")<<tr("9th")<<tr("10th");
        Style->ui->label_Title->setText(Title.at(Number));
        Style->ui->lineEdit_1->setText(Data.at(0));
        Style->ui->lineEdit_2->setText(Data.at(1));
        Style->ui->lineEdit_3->setText(Data.at(2));
    }
    else
    {
        QStringList Title;
        Title<<tr("Suckb1")<<tr("Suckb2");
        Style->ui->label_Title->setText(Title.at(Number));
        Style->ui->lineEdit_1->setText(Data.at(0));
        Style->ui->lineEdit_2->setEnabled(false);
        Style->ui->lineEdit_3->setText(Data.at(1));
    }
}

void MoldCondition_Form::on_pushButton_Refresh_clicked()
{
    Show();
}

void MoldCondition_Form::on_pushButton_Printer_clicked()
{

}

void MoldCondition_Form::resizeEvent(QResizeEvent *)
{
    QFont font,font1;
    font.setPointSizeF(this->width()/86);
    font1.setPointSizeF(this->width()/105);
    font.setBold(true);

    if(font.pointSizeF()<=10)
    {
        font.setPointSizeF(10);
    }

    if(font1.pointSizeF()<=9)
    {
        font1.setPointSizeF(9);
    }

    for(int i=0; i<16; i++)
    {
        if(i<10)
        {
            InjWidgetStyle.at(i)->ui->label_Title->setFont(font);
            InjWidgetStyle.at(i)->ui->lineEdit_1->setFont(font1);
            InjWidgetStyle.at(i)->ui->lineEdit_2->setFont(font1);
            InjWidgetStyle.at(i)->ui->lineEdit_3->setFont(font1);
        }
        if(i<5)
        {
            HoldPWidgetStyle.at(i)->ui->label_Title->setFont(font);
            HoldPWidgetStyle.at(i)->ui->lineEdit_1->setFont(font1);
            HoldPWidgetStyle.at(i)->ui->lineEdit_2->setFont(font1);
            HoldPWidgetStyle.at(i)->ui->lineEdit_3->setFont(font1);
        }
        if(i<3)
        {
            ChgWidgetStyle.at(i)->ui->label_Title->setFont(font);
            ChgWidgetStyle.at(i)->ui->lineEdit_1->setFont(font1);
            ChgWidgetStyle.at(i)->ui->lineEdit_2->setFont(font1);
            ChgWidgetStyle.at(i)->ui->lineEdit_3->setFont(font1);
        }

        if(i<2)
        {
            SuckbWidgetStyle.at(i)->ui->label_Title->setFont(font);
            SuckbWidgetStyle.at(i)->ui->lineEdit_1->setFont(font1);
            SuckbWidgetStyle.at(i)->ui->lineEdit_2->setFont(font1);
            SuckbWidgetStyle.at(i)->ui->lineEdit_3->setFont(font1);
        }

        TempWidgetStyle.at(i)->ui->label_Title->setFont(font);
        TempWidgetStyle.at(i)->ui->lineEdit_1->setFont(font1);
        TempWidgetStyle.at(i)->ui->lineEdit_2->setFont(font1);
    }

    ui->label_Title_Chg_Bps->setFont(font1);
    ui->label_Title_Chg_Pos->setFont(font1);
    ui->label_Title_Chg_Spd->setFont(font1);
    ui->label_Title_ExternTemp_Act->setFont(font1);
    ui->label_Title_ExternTemp_Set->setFont(font1);
    ui->label_Title_Heater_Set->setFont(font1);
    ui->label_Title_Heater_Act->setFont(font1);
    ui->label_Title_Hold_Time->setFont(font1);
    ui->label_Title_Hold_Prs->setFont(font1);
    ui->label_Title_Hold_Spd->setFont(font1);
    ui->label_Title_Inj_Pos->setFont(font1);
    ui->label_Title_Inj_Prs->setFont(font1);
    ui->label_Title_Inj_Spd->setFont(font1);
    ui->lineEdit_ChgDelTime->setFont(font1);
    ui->lineEdit_InjDelTime->setFont(font1);
    ui->lineEdit_InjTime->setFont(font1);
    ui->lineEdit_CoolTime->setFont(font1);
    ui->lineEdit_SOVPos->setFont(font1);
    ui->lineEdit_SOVPrs->setFont(font1);

    font.setPointSizeF(this->width()/43);
    font.setBold(true);
    if(font.pointSizeF()<=20)
    {
        font.setPointSizeF(20);
    }
    ui->label_Title->setFont(font);

    font.setPointSizeF(this->width()/83);
    font.setBold(true);
    if(font.pointSizeF()<=12)
    {
        font.setPointSizeF(12);
    }
    ui->label_DateTime->setFont(font);
    ui->label_Title_Chg->setFont(font);
    ui->label_Title_ChgDelTime->setFont(font);
    ui->label_Title_CoolTime->setFont(font);
    ui->label_Title_ExternTemp->setFont(font);
    ui->label_Title_Heater->setFont(font);
    ui->label_Title_Inj->setFont(font);
    ui->label_Title_Hold->setFont(font);
    ui->label_Title_InjDelTime->setFont(font);
    ui->label_Title_InjTime->setFont(font);
    ui->label_Title_SOVPos->setFont(font);
    ui->label_Title_SOVPrs->setFont(font);
}
