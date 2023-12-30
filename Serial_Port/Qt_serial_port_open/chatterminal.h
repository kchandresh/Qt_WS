#ifndef CHATTERMINAL_H
#define CHATTERMINAL_H

#include <QWidget>

namespace Ui {
class ChatTerminal;
}

class ChatTerminal : public QWidget
{
    Q_OBJECT

public:
    explicit ChatTerminal(QWidget *parent = nullptr);
    ~ChatTerminal();

private:
    Ui::ChatTerminal *ui;
};

#endif // CHATTERMINAL_H
