#include "chatterminal.h"
#include "ui_chatterminal.h"


ChatTerminal::ChatTerminal(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChatTerminal)
{
    ui->setupUi(this);
}

ChatTerminal::~ChatTerminal()
{
    delete ui;
}

void ChatTerminal::on_pushButton_clicked()
{

}

