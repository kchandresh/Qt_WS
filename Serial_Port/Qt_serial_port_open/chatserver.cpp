#include "ChatServer.h"

ChatServer::ChatServer(QObject *parent)
    : QTcpServer(parent) {
    connect(this, &ChatServer::newConnection, this, &ChatServer::incomingConnection);
}

void ChatServer::incomingConnection(qintptr socketDescriptor) {
    QTcpSocket *clientSocket = new QTcpSocket(this);
    clientSocket->setSocketDescriptor(socketDescriptor);

    connect(clientSocket, &QTcpSocket::readyRead, this, &ChatServer::processMessage);
    connect(clientSocket, &QTcpSocket::disconnected, this, &ChatServer::clientDisconnected);

    clients[clientSocket] = QString("Client %1").arg(clients.size() + 1);

    emit newMessage(QString("Server: %1 connected").arg(clients[clientSocket]));
}

void ChatServer::processMessage() {
    QTcpSocket *senderSocket = qobject_cast<QTcpSocket*>(sender());
    if (!senderSocket)
        return;

    QString message = QString::fromUtf8(senderSocket->readAll());
    emit newMessage(QString("%1: %2").arg(clients[senderSocket]).arg(message));
}

void ChatServer::clientDisconnected() {
    QTcpSocket *senderSocket = qobject_cast<QTcpSocket*>(sender());
    if (!senderSocket)
        return;

    emit newMessage(QString("Server: %1 disconnected").arg(clients[senderSocket]));
    clients.remove(senderSocket);
    senderSocket->deleteLater();
}
