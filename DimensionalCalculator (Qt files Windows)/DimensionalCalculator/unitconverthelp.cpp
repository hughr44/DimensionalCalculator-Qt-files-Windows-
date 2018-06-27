#include "unitconverthelp.h"
#include "ui_unitconverthelp.h"

unitConvertHelp::unitConvertHelp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::unitConvertHelp)
{
    ui->setupUi(this);
}

unitConvertHelp::~unitConvertHelp()
{
    delete ui;
}
