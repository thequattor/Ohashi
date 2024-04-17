#ifndef TCP_CLIENT_H
#define TCP_CLIENT_H

#include <QObject>
#include <QString>
#include <QTcpSocket>

#include "common.h"

class TcpClient : public QObject {
   Q_OBJECT

private:
    QTcpSocket *clientSock;
    bool disconnectEvent;

    void disconnectSignals();

    friend void displayDyteArray(QByteArray &hex_data);

public:
    TcpClient();
    ~TcpClient();
    int start_client(QString &ip, QString &port, bool disconn_event);

signals:
    void recv_from_remote_server(QByteArray &msg);
    void server_closed_the_connection();

private slots:
    void on_connected();
    void on_closed_connection();
    void on_ready_read();
    void on_error(QAbstractSocket::SocketError err);
    void on_send_to_remote_server(QByteArray &msg);
    void on_client_closed_the_connection();
};

#endif // TCP_CLIENT_H
