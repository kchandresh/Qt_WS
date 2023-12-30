#include "ChatClient.h"

ChatClient::ChatClient(QObject *parent)
    : QTcpSocket(parent) {
    connect(this, &QTcpSocket::readyRead, this, &ChatClient::processMessage);
}

void ChatClient::processMessage() {
    QString message = QString::fromUtf8(readAll());
    emit newMessage(message);
}

void ChatClient::sendMessage(const QString &message) {
    write(message.toUtf8());
    flush();
}
