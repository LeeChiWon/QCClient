#include "moldcondition_style1.h"
#include "ui_moldcondition_style1.h"

MoldCondition_Style1::MoldCondition_Style1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MoldCondition_Style1)
{
    ui->setupUi(this);
}

MoldCondition_Style1::~MoldCondition_Style1()
{
    delete ui;
}
