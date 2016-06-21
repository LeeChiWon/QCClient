#include "moldcondition_style.h"
#include "ui_moldcondition_style.h"

MoldCondition_Style::MoldCondition_Style(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MoldCondition_Style)
{
    ui->setupUi(this);
}

MoldCondition_Style::~MoldCondition_Style()
{
    delete ui;
}
