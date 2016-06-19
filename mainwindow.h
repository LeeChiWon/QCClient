#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include "configration_form.h"
#include "workplan_form.h"
#include "temperature_form.h"
#include "globalinclude.h"
#include "moldcondition_form.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
     Ui::MainWindow *ui;

    /********** 변수 **********/
    QPointer<Configration_Form> cConfigration_Form; //환경설정화면
    QPointer<WorkPlan_Form> cWorkPlan_Form; //작업계획화면
    QPointer<Temperature_Form> cTemperature_Form; //온도현황판화면
    QPointer<MoldCondition_Form> cMoldCondition_Form;
    QStringList DatabaseInfo; //데이터베이스정보
    QTranslator Translator; //언어변환

    /********** 함수 **********/
    void Init(); //초기화
    void LoadSubWindow(QWidget *widget); //탭화면 생성
    void LanguageChange(int LanguageSelect); //언어변경
signals:
    void Retranslator(); //언어변환
private slots:
    void on_action_Configration_triggered(); //환경설정버튼
    void on_action_Show_WorkPlan_triggered(); //작업계획버튼
    void on_action_Show_Temperature_triggered();

    void on_action_Language_Korean_triggered();

    void on_action_Language_English_triggered();

private:

};

#endif // MAINWINDOW_H
