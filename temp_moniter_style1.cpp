#include "temp_moniter_style1.h"
#include "ui_temp_moniter_style1.h"

temp_moniter_style1::temp_moniter_style1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::temp_moniter_style1)
{
    ui->setupUi(this);
    LocalDB = QSqlDatabase::database("LocalDB");
    number = 0;
}

temp_moniter_style1::~temp_moniter_style1()
{
    delete ui;
}

void temp_moniter_style1::on_templist_currentIndexChanged(int index)
{
    QSqlQuery localquery(LocalDB);
    QString querystr = QString("update temp_setindex set temp%1 = %2 ").arg(number).arg(index);
    localquery.exec(querystr);
}
