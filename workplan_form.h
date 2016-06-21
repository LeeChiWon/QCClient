#ifndef WORKPLAN_FORM_H
#define WORKPLAN_FORM_H

#include <QWidget>
#include <QtWidgets>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QFont>
#include <QTimer>
#include <QTime>
#define WORKPLANLOOPTIME 1500
namespace Ui {
class WorkPlan_Form;
}

class WorkPlan_Form : public QWidget
{
    Q_OBJECT

public:
    explicit WorkPlan_Form(QWidget *parent = 0);
    QSqlDatabase LocalDB;
    QSqlDatabase RemoteDB;
    QTimer timer;
    Ui::WorkPlan_Form *ui;
    ~WorkPlan_Form();

private slots:
    void on_comboBox_MachineName_currentIndexChanged(const QString &arg1);
    void main_update_loop();
    void Retranslator();

    void on_mold_set_btn_clicked();

    void on_worker_set_btn_clicked();

private:

    void resizeEvent(QResizeEvent *);
};

#endif // WORKPLAN_FORM_H
