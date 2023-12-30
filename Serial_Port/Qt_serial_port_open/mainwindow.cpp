#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "chatterminal.h"
#include <QDebug>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , _serialPort(nullptr)
{
    ui->setupUi(this);
    QString styleSheet = "background-color: orange;";
    this->setStyleSheet(styleSheet);
    loadports();

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_tabWidget_tabBarClicked(int index)
{
//    ChatTerminal *chatterminal = new ChatTerminal(this);

//    // Set the size and position of the ChatTerminal
//    chatterminal->setGeometry(10, 10, 300, 200);
//    // Show the ChatTerminal
//    chatterminal->show();
}


void MainWindow::on_pushButton_clicked()
{


}

void MainWindow::loadports()
{

    foreach (auto &port, QSerialPortInfo::availablePorts()){
        ui->comboBox->addItem(port.portName());
    }

}

void MainWindow::on_Select_clicked()
{
    if(_serialPort!=nullptr)
    {
        _serialPort->close();
        delete _serialPort;
    }
    _serialPort=new QSerialPort(this);
    _serialPort->setPortName(ui->comboBox->currentText());
    _serialPort->setBaudRate(QSerialPort::Baud9600);
    _serialPort->setDataBits(QSerialPort::Data8);
    _serialPort->setParity(QSerialPort::NoParity);
    if(_serialPort->open(QIODevice::ReadWrite))
    {
        QMessageBox::information(this, "result", "Port openend sucssefully");
    }
    else{
        QMessageBox::information(this, "Failed", "unable to open port");
    }
}


