#ifndef MOLDCONDITION_STYLE_H
#define MOLDCONDITION_STYLE_H

#include <QWidget>

namespace Ui {
class MoldCondition_Style;
}

class MoldCondition_Style : public QWidget
{
    Q_OBJECT

public:
    explicit MoldCondition_Style(QWidget *parent = 0);
    ~MoldCondition_Style();

private:
    Ui::MoldCondition_Style *ui;
};

#endif // MOLDCONDITION_STYLE_H
