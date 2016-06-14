#include "temperature_form.h"
#include "ui_temperature_form.h"
#include "ui_temp_moniter_style1.h"


Temperature_Form::Temperature_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Temperature_Form)
{
    ui->setupUi(this);



}

Temperature_Form::~Temperature_Form()
{
    delete ui;
}
