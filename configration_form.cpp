#include "configration_form.h"
#include "ui_configration_form.h"

Configration_Form::Configration_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Configration_Form)
{
    ui->setupUi(this);
}

Configration_Form::~Configration_Form()
{
    delete ui;
}
