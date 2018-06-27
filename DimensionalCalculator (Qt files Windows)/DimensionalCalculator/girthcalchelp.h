#ifndef GIRTHCALCHELP_H
#define GIRTHCALCHELP_H

#include <QDialog>

namespace Ui {
class girthCalcHelp;
}

class girthCalcHelp : public QDialog
{
    Q_OBJECT

public:
    explicit girthCalcHelp(QWidget *parent = 0);
    ~girthCalcHelp();

private:
    Ui::girthCalcHelp *ui;
};

#endif // GIRTHCALCHELP_H
