#include "temperature_form.h"
#include "ui_temperature_form.h"

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
