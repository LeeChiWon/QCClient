#ifndef CONFIGRATION_FORM_H
#define CONFIGRATION_FORM_H

#include <QWidget>

namespace Ui {
class Configration_Form;
}

class Configration_Form : public QWidget
{
    Q_OBJECT

public:
    explicit Configration_Form(QWidget *parent = 0);
    ~Configration_Form();

private:
    Ui::Configration_Form *ui;
};

#endif // CONFIGRATION_FORM_H
