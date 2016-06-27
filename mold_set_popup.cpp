#include "mold_set_popup.h"
#include "ui_mold_set_popup.h"
#include "workplan_form.h"
#include "ui_workplan_form.h"

mold_set_popup::mold_set_popup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mold_set_popup)
{
    ui->setupUi(this);
    remotedb = QSqlDatabase::database("RemoteDB");
    sqlmodel = new QSqlTableModel(this,remotedb);
    ui->tableView->setModel(sqlmodel);
    sqlmodel->setTable("mold_info");

    sqlmodel->select();
    sqlmodel->setHeaderData(0,Qt::Horizontal,QVariant(tr("moldname")));
    sqlmodel->setHeaderData(1,Qt::Horizontal,QVariant(tr("itemname")));
    sqlmodel->setHeaderData(2,Qt::Horizontal,QVariant(tr("itmecode")));
    ui->retranslateUi(this);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);


}

mold_set_popup::~mold_set_popup()
{
    delete ui;
}

void mold_set_popup::on_buttonBox_accepted()
{
    WorkPlan_Form *mw1 = (WorkPlan_Form *)parentWidget();
    QSqlQuery query(remotedb);
    QSqlRecord select_recode = sqlmodel->record(selectmodel.row());
    mw1->ui->mold_name_edit->setText(select_recode.value("mold_name").toString());
    mw1->ui->item_code_value_label->setText(select_recode.value("item_code").toString());
    mw1->ui->item_name_value_label->setText(select_recode.value("item_name").toString());
    QString querystr = QString("update Systeminfo set mold_name = \'%1\',"
                               "item_code = \'%2\',"
                               "item_name = \'%3\' "
                               "where machine_name = \'%4\'")
            .arg(select_recode.value("mold_name").toString())
            .arg(select_recode.value("item_code").toString())
            .arg(select_recode.value("item_name").toString())
            .arg(mw1->ui->comboBox_MachineName->currentText());
    query.exec(querystr);

    sqlmodel->submit();
    this->deleteLater();

}
void mold_set_popup::closeEvent(QCloseEvent *){
    this->deleteLater();
}


void mold_set_popup::on_moldadder_btn_clicked()
{
    sqlmodel->insertRow(sqlmodel->rowCount());
    QSqlRecord recode = sqlmodel->record(sqlmodel->rowCount()-1);
    recode.setValue("mold_name","noname");
    sqlmodel->setRecord(sqlmodel->rowCount()-1,recode);

}

void mold_set_popup::on_molddelete_btn_clicked()
{
    sqlmodel->removeRow(selectmodel.row());
}

void mold_set_popup::on_tableView_clicked(const QModelIndex &index)
{
    selectmodel = index;
}


void mold_set_popup::on_serarch_btn_clicked()
{

    sqlmodel->setFilter(QString("mold_name like \'%1%\'").arg(ui->mold_name_serarch_edit->text()));
    sqlmodel->select();
}

void mold_set_popup::on_buttonBox_rejected()
{
    this->deleteLater();
}
