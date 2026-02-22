#ifndef _MAINWINDOW_H_
#define _MAINWINDOW_H_

#include "Calculator.hpp"
#include <qgridlayout.h>
#include <qlineedit.h>
#include <qlistwidget.h>
#include <qmainwindow.h>
#include <qpushbutton.h>
#include <QApplication>
#include <qtmetamacros.h>

class MainWindow : public QMainWindow {

    Q_OBJECT; //macro

    Calculator calc;

    QLineEdit* affichage;

    QPushButton* btn0;
    QPushButton* btn1;
    QPushButton* btn2;
    QPushButton* btn3;
    QPushButton* btn4;
    QPushButton* btn5;
    QPushButton* btn6;
    QPushButton* btn7;
    QPushButton* btn8;
    QPushButton* btn9;
    QPushButton* btn_plus;
    QPushButton* btn_minus;
    QPushButton* btn_multi;
    QPushButton* btn_divide;
    QPushButton* btnCE;
    QPushButton* btn_exe;
    
    QListWidget* history;

    void setupUI();
    void connectSignals();

private slots:

    void onDigitClicked();
    void onOperatorClicked();
    void onEqualClicked();
    void onClearClicked();

public :
    MainWindow();
};

#endif