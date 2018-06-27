#include "dimcalchelp.h"
#include "ui_dimcalchelp.h"

dimCalcHelp::dimCalcHelp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dimCalcHelp)
{
    ui->setupUi(this);
}

dimCalcHelp::~dimCalcHelp()
{
    delete ui;
}
