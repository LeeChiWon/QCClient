#ifndef MOLD_SET_POPUP_H
#define MOLD_SET_POPUP_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QStandardItemModel>
#include <QSqlTableModel>
#include <QSqlRecord>

namespace Ui {
class mold_set_popup;
}

class mold_set_popup : public QDialog
{
    Q_OBJECT

public:
    explicit mold_set_popup(QWidget *parent = 0);
    QStandardItemModel *modal;
    QSqlTableModel *sqlmodel;
    QModelIndex selectmodel;
    QSqlDatabase remotedb;

    ~mold_set_popup();

private slots:
    void on_buttonBox_accepted();
    void closeEvent(QCloseEvent *);

    void on_moldadder_btn_clicked();

    void on_molddelete_btn_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_serarch_btn_clicked();

    void on_buttonBox_rejected();

private:
    Ui::mold_set_popup *ui;
};

#endif // MOLD_SET_POPUP_H
