#ifndef TEMPERATURE_FORM_H
#define TEMPERATURE_FORM_H

#include <QWidget>

namespace Ui {
class Temperature_Form;
}

class Temperature_Form : public QWidget
{
    Q_OBJECT

public:
    explicit Temperature_Form(QWidget *parent = 0);
    ~Temperature_Form();

private:
    Ui::Temperature_Form *ui;
};

#endif // TEMPERATURE_FORM_H
