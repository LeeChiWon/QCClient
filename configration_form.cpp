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
