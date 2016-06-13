#ifndef WORKPLAN_FORM_H
#define WORKPLAN_FORM_H

#include <QWidget>

namespace Ui {
class WorkPlan_Form;
}

class WorkPlan_Form : public QWidget
{
    Q_OBJECT

public:
    explicit WorkPlan_Form(QWidget *parent = 0);
    ~WorkPlan_Form();

private:
    Ui::WorkPlan_Form *ui;
};

#endif // WORKPLAN_FORM_H
