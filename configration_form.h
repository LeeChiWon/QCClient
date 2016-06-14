#ifndef CONFIGRATION_FORM_H
#define CONFIGRATION_FORM_H

#include <QWidget>
#include <QtWidgets>
#include <QSqlDatabase>
#include <QSqlQuery>

namespace Ui {
class Configration_Form;
}

class Configration_Form : public QWidget
{
    Q_OBJECT

public:
    explicit Configration_Form(QWidget *parent = 0);
    ~Configration_Form();

    /********** 변수 **********/
    QSqlDatabase LocalDB; //서버 데이터베이스 셋팅 저장 및 불러오는 데이터베이스
    /********** 함수 **********/
    void resizeEvent(QResizeEvent*);
    void Init(); //초기화
    void DatabaseSettingMode(int Mode); //데이터베이스설정 모드
    void DatabaseSettingInit(); //데이터베이스설정 초기화
    void DatabaseSettingSave(); //데이터베이스설정 저장

private slots:
    void on_pushButton_Check_clicked();
    void on_pushButton_Apply_clicked();
    void on_pushButton_Cancel_clicked();

private:
    Ui::Configration_Form *ui;
};

#endif // CONFIGRATION_FORM_H
