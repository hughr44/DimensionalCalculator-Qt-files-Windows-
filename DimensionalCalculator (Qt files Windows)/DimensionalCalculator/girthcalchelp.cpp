#include "girthcalchelp.h"
#include "ui_girthcalchelp.h"

girthCalcHelp::girthCalcHelp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::girthCalcHelp)
{
    ui->setupUi(this);
}

girthCalcHelp::~girthCalcHelp()
{
    delete ui;
}
