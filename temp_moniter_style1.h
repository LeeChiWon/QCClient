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
    Ui::temp_moniter_style1 *ui;
    int number;  //어디위치의 위젯인지 구분하기 위해서 넣어줌
    ~temp_moniter_style1();

private:

};

#endif // TEMP_MONITER_STYLE1_H
