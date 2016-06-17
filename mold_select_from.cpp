#include "mold_select_from.h"
#include "ui_mold_select_from.h"

mold_select_from::mold_select_from(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mold_select_from)
{
    ui->setupUi(this);
}

mold_select_from::~mold_select_from()
{
    delete ui;
}
