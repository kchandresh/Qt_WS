#ifndef CHATSERVER_H
#define CHATSERVER_H

#include <QTcpServer>
#include <QTcpSocket>

class ChatServer : public QTcpServer {
    Q_OBJECT

public:
    ChatServer(QObject *parent = nullptr);

protected:
    void incomingConnection(qintptr socketDescriptor) override;

signals:
    void newMessage(const QString &message);

private:
    QHash<QTcpSocket*, QString> clients;

private slots:
    void processMessage();
    void clientDisconnected();
};

#endif // CHATSERVER_H
