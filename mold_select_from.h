#ifndef MOLD_SELECT_FROM_H
#define MOLD_SELECT_FROM_H

#include <QDialog>

namespace Ui {
class mold_select_from;
}

class mold_select_from : public QDialog
{
    Q_OBJECT

public:
    explicit mold_select_from(QWidget *parent = 0);
    ~mold_select_from();

private:
    Ui::mold_select_from *ui;
};

#endif // MOLD_SELECT_FROM_H
