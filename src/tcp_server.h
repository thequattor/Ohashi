#ifndef TCP_SERVER_H
#define TCP_SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QXmlStreamReader>
#include <QNetworkInterface>

#include "common.h"

class TcpServer : public QObject {
    //Q_OBJECT

private:
    QTcpServer *tcpServer;
    QTcpSocket *tcpSocketFirstClient;
    QTcpSocket *tcpSocketSecondClient;

    int client_0_connected;
    int client_1_connected;
    int client_last_active;
    bool disconnect_event;
    bool client_mode;

    void connect_signals(int client_number);
    void disconnect_signals(int client_number);
    friend void display_byte_array(QByteArray &hex_data);

public:
    TcpServer();
    ~TcpServer();
    int start_server(QString &ip, QString &port, bool disconn_event, bool cli_mode);
    void close_client_socket_0();
    void close_client_socket_1();
    void send_to_client(QByteArray &msg, int client_number);

signals:
    void user_client_connected_0();
    void user_client_connected_1();
    void send_to_remote_server(QByteArray &msg);
    void client_closed_the_connection();

private slots:
    void on_new_connection();
    void on_closed_connection_0();
    void on_ready_read_0();
    void on_closed_connection_1();
    void on_ready_read_1();
    void on_recv_from_remote_server(QByteArray &msg);
    void on_server_closed_the_connection();
};

#endif // TCP_SERVER_H
