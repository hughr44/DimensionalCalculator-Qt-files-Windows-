#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "unitconverthelp.h"
#include "dimcalchelp.h"
#include "girthcalchelp.h"
#include <QDoubleValidator>
#include <string>
#include <iostream>
#include <iomanip>
#include <QDebug>
#include <cmath>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QDoubleValidator *dimensionValidator = new QDoubleValidator(0.000, 10000.000, 4);
    ui->lineEdit->setValidator(dimensionValidator);
    ui->lineEdit_3->setValidator(dimensionValidator);
    ui->lineEdit_4->setValidator(dimensionValidator);
    ui->lineEdit_5->setValidator(dimensionValidator);
    ui->lineEdit_8->setValidator(dimensionValidator);
    ui->lineEdit_9->setValidator(dimensionValidator);
    ui->lineEdit_10->setValidator(dimensionValidator);

    connect(ui->radioButton,SIGNAL(clicked()),this,SLOT(weight_selected()));
    connect(ui->radioButton_2,SIGNAL(clicked()),this,SLOT(length_selected()));

    connect(ui->pushButton,SIGNAL(released()),this,SLOT(convertUnit_pressed()));
    connect(ui->pushButton_2,SIGNAL(released()),this,SLOT(dimensionalWeight_pressed()));
    connect(ui->pushButton_3,SIGNAL(released()),this,SLOT(girth_pressed()));

    connect(ui->pushButton_4,SIGNAL(released()),this,SLOT(unitConvertHelp_pressed()));
    connect(ui->pushButton_5,SIGNAL(released()),this,SLOT(dimCalcHelp_pressed()));
    connect(ui->pushButton_6,SIGNAL(released()),this,SLOT(girthCalcHelp_pressed()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::weight_selected(){
    ui->radioButton_8->hide();
    ui->radioButton_9->hide();
    ui->radioButton_10->hide();
    ui->radioButton_11->hide();
    ui->radioButton_12->hide();

    ui->radioButton_3->show();
    ui->radioButton_4->show();
    ui->radioButton_5->show();
    ui->radioButton_6->show();
    ui->radioButton_7->show();

    ui->radioButton_18->hide();
    ui->radioButton_19->hide();
    ui->radioButton_20->hide();
    ui->radioButton_21->hide();
    ui->radioButton_22->hide();

    ui->radioButton_13->show();
    ui->radioButton_14->show();
    ui->radioButton_15->show();
    ui->radioButton_16->show();
    ui->radioButton_17->show();
}

void MainWindow::length_selected(){
    ui->radioButton_3->hide();
    ui->radioButton_4->hide();
    ui->radioButton_5->hide();
    ui->radioButton_6->hide();
    ui->radioButton_7->hide();

    ui->radioButton_8->show();
    ui->radioButton_9->show();
    ui->radioButton_10->show();
    ui->radioButton_11->show();
    ui->radioButton_12->show();

    ui->radioButton_13->hide();
    ui->radioButton_14->hide();
    ui->radioButton_15->hide();
    ui->radioButton_16->hide();
    ui->radioButton_17->hide();

    ui->radioButton_18->show();
    ui->radioButton_19->show();
    ui->radioButton_20->show();
    ui->radioButton_21->show();
    ui->radioButton_22->show();
}

void MainWindow::convertUnit_pressed()
{
    QPushButton * button = (QPushButton*)sender();

    QString newLabel;
    newLabel = button->text();

    double inputVal;
    QString inputString;
    inputString = ui->lineEdit->text();
    inputVal = inputString.toDouble();

    bool metricInput = true;
    bool metricOutput = true;
    double tempVal;

    QString inputUnits;
    QString outputUnits;

    if(ui->radioButton->isChecked()){ //weight and mass
        if(ui->radioButton_3->isChecked()){
            metricInput = false;
            tempVal = inputVal * 16;
            inputUnits = "Pounds";
        }
        if(ui->radioButton_4->isChecked()){
            metricInput = false;
            tempVal = inputVal;
            inputUnits = "Ounces";
        }
        if(ui->radioButton_5->isChecked()){
            metricInput = true;
            tempVal = inputVal * .001;
            inputUnits = "Milligrams";
        }
        if(ui->radioButton_6->isChecked()){
            metricInput = true;
            tempVal = inputVal;
            inputUnits = "Grams";
        }
        if(ui->radioButton_7->isChecked()){
            metricInput = true;
            tempVal = inputVal * 1000;
            inputUnits = "Kilograms";
        }
        if(ui->radioButton_13->isChecked() || ui->radioButton_14->isChecked()){
            metricOutput = false;
        }
        if(metricInput && !metricOutput){
            tempVal = tempVal * 0.03527396195;
        }
        if(!metricInput && metricOutput){
            tempVal = tempVal * 28.34952;
        }
        if(ui->radioButton_13->isChecked()){
            tempVal = tempVal / 16;
            outputUnits = "Pounds";
        }
        if(ui->radioButton_14->isChecked()){
            //tempVal = tempVal;
            outputUnits = "Ounces";
        }
        if(ui->radioButton_15->isChecked()){
            tempVal = tempVal * 1000;
            outputUnits = "Milligrams";
        }
        if(ui->radioButton_16->isChecked()){
            //tempVal = tempVal;
            outputUnits = "Grams";
        }
        if(ui->radioButton_17->isChecked()){
            tempVal = tempVal * .001;
            outputUnits = "Kilograms";
        }
    }
    if(ui->radioButton_2->isChecked()){ //length
        if(ui->radioButton_8->isChecked()){
            metricInput = false;
            tempVal = inputVal;
            inputUnits = "Inches";
        }
        if(ui->radioButton_9->isChecked()){
            metricInput = false;
            tempVal = inputVal * 12;
            inputUnits = "Feet";
        }
        if(ui->radioButton_10->isChecked()){
            metricInput = true;
            tempVal = inputVal * .1;
            inputUnits = "Millimeters";
        }
        if(ui->radioButton_11->isChecked()){
            metricInput = true;
            tempVal = inputVal;
            inputUnits = "Centimeters";
        }
        if(ui->radioButton_12->isChecked()){
            metricInput = true;
            tempVal = inputVal * 100;
            inputUnits = "Meters";
        }
        if(ui->radioButton_18->isChecked() || ui->radioButton_19->isChecked()){
            metricOutput = false;
        }
        if(metricInput && !metricOutput){
            tempVal = tempVal * .393701;
        }
        if(!metricInput && metricOutput){
            tempVal = tempVal * 2.54;
        }
        if(ui->radioButton_18->isChecked()){
            //tempVal = tempVal;
            outputUnits = "Inches";
        }
        if(ui->radioButton_19->isChecked()){
            tempVal = tempVal / 12;
            outputUnits = "Feet";
        }
        if(ui->radioButton_20->isChecked()){
            tempVal = tempVal * 10;
            outputUnits = "Millimeters";
        }
        if(ui->radioButton_21->isChecked()){
            //tempVal = tempVal;
            outputUnits = "Centimeters";
        }
        if(ui->radioButton_22->isChecked()){
            tempVal = tempVal / 100;
            outputUnits = "Meters";
        }
    }

    double outputVal = tempVal;
    QString outputString;
    outputString = QString::number(outputVal, 'g', 15); // format for output specified here
    ui->lineEdit_2->setText(outputString);

    ui->label_29->setText(inputUnits);
    ui->label_29->update();
    ui->label_29->repaint();

    ui->label_30->setText(outputUnits);
    ui->label_30->update();
    ui->label_30->repaint();
}

void MainWindow::dimensionalWeight_pressed(){
    QPushButton * button = (QPushButton*)sender();

    QString newLabel;
    newLabel = button->text();

    double length;
    double width;
    double height;

    QString lengthString;
    QString widthString;
    QString heightString;

    lengthString = ui->lineEdit_3->text();
    length = lengthString.toDouble();
    widthString = ui->lineEdit_4->text();
    width = widthString.toDouble();
    heightString = ui->lineEdit_5->text();
    height = heightString.toDouble();

    /*if(ui->radioButton_23->isChecked()){
        length = length;
        width = width;
        height = height;
    }*/
    if(ui->radioButton_24->isChecked()){
        length = length * 12;
        width = width * 12;
        height = height * 12;
    }
    if(ui->radioButton_25->isChecked()){
        length = length * 0.0393701;
        width = width * 0.0393701;
        height = height * 0.0393701;
    }
    if(ui->radioButton_26->isChecked()){
        length = length * 0.393701;
        width = width * 0.393701;
        height = height * 0.393701;
    }
    if(ui->radioButton_27->isChecked()){
        length = length * 39.3701;
        width = width * 39.3701;
        height = height * 39.3701;
    }

    // round length width height to nearest whole inch value
    length = (double)qRound(length);
    width = (double)qRound(width);
    height = (double)qRound(height);

    double dimDivisor;
    if(ui->radioButton_28->isChecked()){
        dimDivisor = 166;
    }
    if(ui->radioButton_29->isChecked()){
        dimDivisor = 194;
    }
    if(ui->radioButton_30->isChecked()){
        dimDivisor = 139;
    }
    if(ui->radioButton_31->isChecked()){
        dimDivisor = 139;
    }
    if(ui->radioButton_32->isChecked()){
        dimDivisor = 139;
    }
    if(ui->radioButton_43->isChecked()){
        dimDivisor = 139;
    }
    if(ui->radioButton_44->isChecked()){
        dimDivisor = 166;
    }

    double tempVal = (length * width * height) / dimDivisor;

    double outputValLbs = tempVal;
    double outputValKgs = tempVal * 0.453592;

    //qDebug() << outputValLbs << " " << outputValKgs;

    outputValLbs = ceil(outputValLbs);
    outputValKgs = ( qRound ( ( outputValKgs * 2 ) + 0.49999 ) / 2.0 );

    //qDebug() << outputValLbs << " " << outputValKgs;

    QString outputStringLbs;
    QString outputStringKgs;
    outputStringLbs = QString::number(outputValLbs, 'g');
    outputStringKgs = QString::number(outputValKgs, 'g');
    ui->lineEdit_6->setText(outputStringLbs);
    ui->lineEdit_7->setText(outputStringKgs);
}

void MainWindow::girth_pressed(){
    QPushButton * button = (QPushButton*)sender();

    QString newLabel;
    newLabel = button->text();

    double length;
    double width;
    double height;

    QString lengthString;
    QString widthString;
    QString heightString;

    lengthString = ui->lineEdit_8->text();
    length = lengthString.toDouble();
    widthString = ui->lineEdit_9->text();
    width = widthString.toDouble();
    heightString = ui->lineEdit_10->text();
    height = heightString.toDouble();

    QString equationUsed1;
    QString equationUsed2;
    double girthDim1;
    double girthDim2;
    if(height > length && height > width){
        equationUsed1 = "Height is the largest dimension";
        equationUsed2 = "Equation Used: Girth = ( 2 x Length ) + ( 2 x Width )";
        girthDim1 = length;
        girthDim2 = width;
    }
    else if(width > length && width > height){
        equationUsed1 = "Width is the largest dimension";
        equationUsed2 = "Equation Used: Girth = ( 2 x Length ) + ( 2 x Height )";
        girthDim1 = length;
        girthDim2 = height;
    }
    else{
        equationUsed1 = "Length is the largest dimension";
        equationUsed2 = "Equation Used: Girth = ( 2 x Width ) + ( 2 x Height )";
        girthDim1 = width;
        girthDim2 = height;
    }

    QString inputUnits;
    QString outputUnits;

    if(ui->radioButton_33->isChecked()){ // set input unit string and convert girthDim 1 and 2 to inches
        inputUnits = "Inches";
        //girthDim1 = girthDim1;
        //girthDim2 = girthDim2;
    }
    else if(ui->radioButton_34->isChecked()){
        inputUnits = "Feet";
        girthDim1 = girthDim1 * 12;
        girthDim2 = girthDim2 * 12;
    }
    else if(ui->radioButton_35->isChecked()){
        inputUnits = "Millimeters";
        girthDim1 = girthDim1 * 0.0393701;
        girthDim2 = girthDim2 * 0.0393701;
    }
    else if(ui->radioButton_36->isChecked()){
        inputUnits = "Centimeters";
        girthDim1 = girthDim1 * 0.393701;
        girthDim2 = girthDim2 * 0.393701;
    }
    else if(ui->radioButton_37->isChecked()){
        inputUnits = "Meters";
        girthDim1 = girthDim1 * 39.3701;
        girthDim2 = girthDim2 * 39.3701;
    }
    else{
        inputUnits = "Inches";
        //girthDim1 = girthDim1;
        //girthDim2 = girthDim2;
    }

    if(ui->radioButton_38->isChecked()){ // set input unit string and convert girthDim 1 and 2 to inches
        outputUnits = "Inches";
        //girthDim1 = girthDim1;
        //girthDim2 = girthDim2;
    }
    else if(ui->radioButton_39->isChecked()){
        outputUnits = "Feet";
        girthDim1 = girthDim1 / 12;
        girthDim2 = girthDim2 / 12;
    }
    else if(ui->radioButton_40->isChecked()){
        outputUnits = "Millimeters";
        girthDim1 = girthDim1 / 0.0393701;
        girthDim2 = girthDim2 / 0.0393701;
    }
    else if(ui->radioButton_41->isChecked()){
        outputUnits = "Centimeters";
        girthDim1 = girthDim1 / 0.393701;
        girthDim2 = girthDim2 / 0.393701;
    }
    else if(ui->radioButton_42->isChecked()){
        outputUnits = "Meters";
        girthDim1 = girthDim1 / 39.3701;
        girthDim2 = girthDim2 / 39.3701;
    }
    else{
        outputUnits = inputUnits;
        if(height > length && height > width){
            girthDim1 = length;
            girthDim2 = width;
        }
        else if(width > length && width > height){
            girthDim1 = length;
            girthDim2 = height;
        }
        else{
            girthDim1 = width;
            girthDim2 = height;
        }
    }

    double girth;
    girth = ( 2 * girthDim1 ) + ( 2 * girthDim2 );

    QString outputString;
    outputString = QString::number(girth, 'f', 5);

    ui->label_24->setText(equationUsed1);
    ui->label_24->update();
    ui->label_24->repaint();

    ui->label_25->setText(equationUsed2);
    ui->label_25->update();
    ui->label_25->repaint();

    ui->label_28->setText(outputUnits);
    ui->label_28->update();
    ui->label_28->repaint();

    ui->lineEdit_11->setText(outputString);
}

void MainWindow::unitConvertHelp_pressed(){
    unitConvertHelp unitConvHelp;
    unitConvHelp.setModal(true);
    unitConvHelp.exec();
}

void MainWindow::dimCalcHelp_pressed(){
    dimCalcHelp dimHelp;
    dimHelp.setModal(true);
    dimHelp.exec();
}

void MainWindow::girthCalcHelp_pressed(){
    girthCalcHelp girthHelp;
    girthHelp.setModal(true);
    girthHelp.exec();
}
