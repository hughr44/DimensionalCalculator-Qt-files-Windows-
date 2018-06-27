#ifndef UNITCONVERTHELP_H
#define UNITCONVERTHELP_H

#include <QDialog>

namespace Ui {
class unitConvertHelp;
}

class unitConvertHelp : public QDialog
{
    Q_OBJECT

public:
    explicit unitConvertHelp(QWidget *parent = 0);
    ~unitConvertHelp();

private:
    Ui::unitConvertHelp *ui;
};

#endif // UNITCONVERTHELP_H
