#ifndef DIMCALCHELP_H
#define DIMCALCHELP_H

#include <QDialog>

namespace Ui {
class dimCalcHelp;
}

class dimCalcHelp : public QDialog
{
    Q_OBJECT

public:
    explicit dimCalcHelp(QWidget *parent = 0);
    ~dimCalcHelp();

private:
    Ui::dimCalcHelp *ui;
};

#endif // DIMCALCHELP_H
