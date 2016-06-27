#ifndef TEMPNAMESET_POPUP_H
#define TEMPNAMESET_POPUP_H

#include <QDialog>
#include <QStandardItemModel>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QModelIndex>

namespace Ui {
class tempnameset_popup;
}

class tempnameset_popup : public QDialog
{
    Q_OBJECT

public:
    explicit tempnameset_popup(QWidget *parent = 0);
    QStandardItemModel *model;
    QSqlDatabase remotedb;
    QSqlDatabase localdb;
    QObject *parent_src;
    QString machinename;
    ~tempnameset_popup();

private:
    Ui::tempnameset_popup *ui;
public slots:
    void tabledatachanged(const QModelIndex & topLeft, const QModelIndex & bottomRight);

};

#endif // TEMPNAMESET_POPUP_H
