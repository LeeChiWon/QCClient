#ifndef MOLDCONDITION_STYLE1_H
#define MOLDCONDITION_STYLE1_H

#include <QWidget>

namespace Ui {
class MoldCondition_Style1;
}

class MoldCondition_Style1 : public QWidget
{
    Q_OBJECT

public:
    explicit MoldCondition_Style1(QWidget *parent = 0);
    ~MoldCondition_Style1();
    Ui::MoldCondition_Style1 *ui;
private:

};

#endif // MOLDCONDITION_STYLE1_H
