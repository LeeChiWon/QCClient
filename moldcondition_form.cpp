#include "moldcondition_form.h"
#include "ui_moldcondition_form.h"

MoldCondition_Form::MoldCondition_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MoldCondition_Form)
{
    ui->setupUi(this);
    Init();
}

MoldCondition_Form::~MoldCondition_Form()
{
    delete ui;
}

void MoldCondition_Form::Init()
{
    QWidget *widget=new QWidget(this);

    QProcess *pp=new QProcess(this);
    pp->start("d:\\3DP_Chip_v1511.exe");
    widget->show();
}
