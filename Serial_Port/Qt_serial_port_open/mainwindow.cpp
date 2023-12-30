#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "chatterminal.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString styleSheet = "background-color: orange;";
    this->setStyleSheet(styleSheet);
    ChatTerminal *chatterminal = new ChatTerminal(this);

    // Set the size and position of the ChatTerminal
    chatterminal->setGeometry(10, 10, 300, 200);

    // Show the ChatTerminal
    chatterminal->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}


