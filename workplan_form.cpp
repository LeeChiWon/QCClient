#include "workplan_form.h"
#include "ui_workplan_form.h"

WorkPlan_Form::WorkPlan_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WorkPlan_Form)
{
    ui->setupUi(this);
}

WorkPlan_Form::~WorkPlan_Form()
{
    delete ui;
}
