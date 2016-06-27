#include "tempnameset_popup.h"
#include "ui_tempnameset_popup.h"
#include "QDebug"
#include "temperature_form.h"

tempnameset_popup::tempnameset_popup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tempnameset_popup)
{
    ui->setupUi(this);
    parent_src = parent;
    model = new QStandardItemModel();
    remotedb = QSqlDatabase::database("RemoteDB");
    localdb = QSqlDatabase::database("LocalDB");
    QSqlQuery remotequery(remotedb);
    QSqlQuery localquery(localdb);
    localquery.exec("select current_macine_name from systemset;");
    localquery.next();
    machinename = localquery.value("current_macine_name").toString();
    ui->tableView->setModel(model);
    model->insertColumn(0);
    model->setHorizontalHeaderItem(0,new QStandardItem(tr("temp name")));
    QString querystr = QString("select ");
    for(int i=1;i<=21;i++){
        if(i==21){
            querystr.append(QString("temp%1_name").arg(i));
        }else {
            querystr.append(QString("temp%1_name,").arg(i));
        }
    }
    querystr.append(QString(" from temp_table where machine_name = \'%2\'").arg(machinename));
    remotequery.exec(querystr);

    remotequery.next();
    for(int i=0;i<21;i++){
        QString temp_name = remotequery.value(i).toString();
        int count = model->rowCount();
        model->insertRow(count,new QStandardItem(temp_name));

    }
    connect(model,SIGNAL(dataChanged(QModelIndex,QModelIndex)),this,SLOT(tabledatachanged(QModelIndex,QModelIndex)));
}
void tempnameset_popup::tabledatachanged(const QModelIndex &topLeft, const QModelIndex &bottomRight){
    Temperature_Form *parent = (Temperature_Form *)parent_src;
    QSqlQuery remotequery(remotedb);
    remotequery.exec(QString("UPDATE temp_table SET temp%1_name=\'%2\' where machine_name = \'%3\'")
                            .arg(topLeft.row()+1).arg(topLeft.data().toString()).arg(machinename)
                     );
    parent->tempnamechagne();

}

tempnameset_popup::~tempnameset_popup()
{
    delete ui;
}

