#ifndef MOLDCONDITION_FORM_H
#define MOLDCONDITION_FORM_H

#include <QWidget>
#include <QtWidgets>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "moldcondition_style.h"
#include "moldcondition_style1.h"

namespace Ui {
class MoldCondition_Form;
}

class MoldCondition_Form : public QWidget
{
    Q_OBJECT

public:
    explicit MoldCondition_Form(QWidget *parent = 0);
    ~MoldCondition_Form();

    /********** 변수 **********/
    QSqlDatabase LocalDB;
    QSqlDatabase RemoteDB;
    QList<MoldCondition_Style*>InjWidgetStyle;
    QList<MoldCondition_Style*>HoldPWidgetStyle;
    QList<MoldCondition_Style*>ChgWidgetStyle;
    QList<MoldCondition_Style*>SuckbWidgetStyle;
    QList<MoldCondition_Style1*>TempWidgetStyle;
    QTimer Mainloop;

    /********** 함수 **********/
    void Init();
    void Show();
    void MoldConditionStyleInit(MoldCondition_Style *Style,int Number, QStringList Data, bool Hide);
    void MoldConditionStyle1Init(MoldCondition_Style1 *Style, QStringList Data, bool Hide);

private slots:
    void on_pushButton_Refresh_clicked();
    void on_pushButton_Printer_clicked();

private:
    Ui::MoldCondition_Form *ui;
    void resizeEvent(QResizeEvent*);
   // Ui::Configration_Form *ui1;
};

#endif // MOLDCONDITION_FORM_H
