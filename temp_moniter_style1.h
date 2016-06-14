#ifndef TEMP_MONITER_STYLE1_H
#define TEMP_MONITER_STYLE1_H

#include <QWidget>

namespace Ui {
class temp_moniter_style1;
}

class temp_moniter_style1 : public QWidget
{
    Q_OBJECT

public:
    explicit temp_moniter_style1(QWidget *parent = 0);
    ~temp_moniter_style1();

private:
    Ui::temp_moniter_style1 *ui;
};

#endif // TEMP_MONITER_STYLE1_H
