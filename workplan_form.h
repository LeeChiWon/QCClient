#ifndef WORKPLAN_FORM_H
#define WORKPLAN_FORM_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QFont>

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
    ~WorkPlan_Form();

private slots:
    void on_comboBox_MachineName_currentIndexChanged(const QString &arg1);

private:
    Ui::WorkPlan_Form *ui;
    void resizeEvent(QResizeEvent *event);
};

#endif // WORKPLAN_FORM_H
