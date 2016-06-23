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

/*void MoldCondition_Style::resizeEvent(QResizeEvent *)
{
    QFont font;
    font.setPointSizeF(this->width()/8);

    if(font.pointSizeF()<=10)
    {
        font.setPointSizeF(10);
    }
    ui->label_Title->setFont(font);

    /*if(font.pointSizeF()<=9)
    {
        font.setPointSizeF(9);
    }*/
   /* ui->lineEdit_1->setFont(font);
    ui->lineEdit_2->setFont(font);
    ui->lineEdit_3->setFont(font);
}*/
