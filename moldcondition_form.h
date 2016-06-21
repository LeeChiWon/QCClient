#ifndef MOLDCONDITION_FORM_H
#define MOLDCONDITION_FORM_H

#include <QWidget>
#include <QtWidgets>

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

    /********** 함수 **********/
    void Init();
private:
    Ui::MoldCondition_Form *ui;
};

#endif // MOLDCONDITION_FORM_H
