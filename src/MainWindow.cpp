#include "../include/MainWindow.hpp"
#include <iostream>
#include <qgridlayout.h>
#include <qlayout.h>
#include <qlineedit.h>
#include <qlistwidget.h>
#include <qobject.h>
#include <qpushbutton.h>
#include <qwidget.h>
#include <sstream>
#include <string>
#include "./../include/Parser.hpp"

MainWindow::MainWindow(){
    setupUI();
    connectSignals();
}

void MainWindow::setupUI() {

    QWidget* central = new QWidget(this);

    history = new QListWidget;

    affichage = new QLineEdit("0");

    QGridLayout* grid_layout = new QGridLayout;

    btn0 = new QPushButton("0");
    btn1 = new QPushButton("1");
    btn2 = new QPushButton("2");
    btn3 = new QPushButton("3");
    btn4 = new QPushButton("4");
    btn5 = new QPushButton("5");
    btn6 = new QPushButton("6");
    btn7 = new QPushButton("7");
    btn8 = new QPushButton("8");
    btn9 = new QPushButton("9");
    btn_plus = new QPushButton("+");
    btn_minus = new QPushButton("-");
    btn_multi = new QPushButton("*");
    btn_divide = new QPushButton("/");
    btnCE = new QPushButton("CE");
    btn_exe = new QPushButton("=");

    grid_layout->addWidget(history, 0, 0, 1, 4);

    grid_layout->addWidget(affichage, 1, 0, 1, 4); // ligne 0, colonne 0, occupe 1 ligne et 4 colonnes

    grid_layout->addWidget(btn0, 5, 0);
    grid_layout->addWidget(btn1, 4, 0);
    grid_layout->addWidget(btn2, 4, 1);
    grid_layout->addWidget(btn3, 4, 2);
    grid_layout->addWidget(btn4, 3, 0);
    grid_layout->addWidget(btn5, 3, 1);
    grid_layout->addWidget(btn6, 3, 2);
    grid_layout->addWidget(btn7, 2, 0);
    grid_layout->addWidget(btn8, 2, 1);
    grid_layout->addWidget(btn9, 2, 2);
    grid_layout->addWidget(btn_plus, 2, 3);
    grid_layout->addWidget(btn_minus, 3, 3);
    grid_layout->addWidget(btn_multi, 4, 3);
    grid_layout->addWidget(btn_divide, 5, 3);
    grid_layout->addWidget(btnCE, 5, 1);
    grid_layout->addWidget(btn_exe, 5, 2);

    central->setLayout(grid_layout);
    setCentralWidget(central);

}

void MainWindow::connectSignals() {

    connect(btn0, &QPushButton::clicked, this, &MainWindow::onDigitClicked);
    connect(btn1, &QPushButton::clicked, this, &MainWindow::onDigitClicked);
    connect(btn2, &QPushButton::clicked, this, &MainWindow::onDigitClicked);
    connect(btn3, &QPushButton::clicked, this, &MainWindow::onDigitClicked);
    connect(btn4, &QPushButton::clicked, this, &MainWindow::onDigitClicked);
    connect(btn5, &QPushButton::clicked, this, &MainWindow::onDigitClicked);
    connect(btn6, &QPushButton::clicked, this, &MainWindow::onDigitClicked);
    connect(btn7, &QPushButton::clicked, this, &MainWindow::onDigitClicked);
    connect(btn8, &QPushButton::clicked, this, &MainWindow::onDigitClicked);
    connect(btn9, &QPushButton::clicked, this, &MainWindow::onDigitClicked);

    connect(btn_plus, &QPushButton::clicked, this, &MainWindow::onOperatorClicked);
    connect(btn_minus, &QPushButton::clicked, this, &MainWindow::onOperatorClicked);
    connect(btn_multi, &QPushButton::clicked, this, &MainWindow::onOperatorClicked);
    connect(btn_divide, &QPushButton::clicked, this, &MainWindow::onOperatorClicked);

    connect(btn_exe, &QPushButton::clicked, this, &MainWindow::onEqualClicked);

    connect(btnCE, &QPushButton::clicked, this, &MainWindow::onClearClicked);

}

void MainWindow::onDigitClicked() {

    QObject* sender_btn = sender();
    QPushButton* btn = qobject_cast<QPushButton*>(sender_btn);

    if (btn == btn0 && (affichage->text() == "0")){
        return;
    } else if (affichage->text() == "0") {
        affichage->setText(btn->text());
    } else {
        affichage->setText(affichage->text() + btn->text());
    }
}

void MainWindow::onOperatorClicked() {

    QObject* sender_btn = sender();
    QPushButton* btn = qobject_cast<QPushButton*>(sender_btn);

    affichage->setText(affichage->text() + btn->text());
}

void MainWindow::onEqualClicked() {

    double result = Parser::evaluate(affichage->text().toStdString());

    std::ostringstream oss;
    oss << result;
    std::string str = oss.str();
    
    history->addItem(affichage->text() + '\t' + QString::fromStdString(oss.str()));
    affichage->setText(QString::fromStdString(oss.str()));

}

void MainWindow::onClearClicked() {
    affichage->setText("");
}