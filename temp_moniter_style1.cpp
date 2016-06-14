#include "temp_moniter_style1.h"
#include "ui_temp_moniter_style1.h"

temp_moniter_style1::temp_moniter_style1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::temp_moniter_style1)
{
    ui->setupUi(this);
}

temp_moniter_style1::~temp_moniter_style1()
{
    delete ui;
}
