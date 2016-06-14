#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include "configration_form.h"
#include "workplan_form.h"
#include "temperature_form.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    /********** 변수 **********/
    QPointer<Configration_Form> cConfigration_Form; //환경설정화면
    QPointer<WorkPlan_Form> cWorkPlan_Form; //작업계획화면
    QPointer<Temperature_Form> cTemperature_Form; //온도현황판화면

    /********** 함수 **********/
    void Init(); //초기화
    void LoadSubWindow(QWidget *widget); //탭화면 생성

private slots:
    void on_action_Configration_triggered(); //환경설정버튼
    void on_action_Show_WorkPlan_triggered(); //작업계획버튼

    void on_action_Show_Temperature_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H