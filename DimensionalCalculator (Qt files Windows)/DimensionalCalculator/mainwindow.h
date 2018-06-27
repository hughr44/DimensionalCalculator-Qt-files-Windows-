#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void weight_selected();
    void length_selected();
    void convertUnit_pressed();
    void dimensionalWeight_pressed();
    void girth_pressed();
    void unitConvertHelp_pressed();
    void dimCalcHelp_pressed();
    void girthCalcHelp_pressed();
};

#endif // MAINWINDOW_H
