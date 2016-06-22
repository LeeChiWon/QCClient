#ifndef MOLDCONDITION_STYLE_H
#define MOLDCONDITION_STYLE_H

#include <QWidget>
#include <QtWidgets>

namespace Ui {
class MoldCondition_Style;
}

class MoldCondition_Style : public QWidget
{
    Q_OBJECT

public:
    explicit MoldCondition_Style(QWidget *parent = 0);
    ~MoldCondition_Style();
    Ui::MoldCondition_Style *ui;

private:

};

#endif // MOLDCONDITION_STYLE_H
