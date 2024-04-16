#include "tcp_server.h"

TcpServer::TcpServer() {
    this->tcpServer = nullptr;
    this->tcpSocketFirstClient = nullptr;
    this->tcpSocketSecondClient = nullptr;

    //tcpsrv = nullptr;
    //client_sock_0 = nullptr;
    //client_sock_1 = nullptr;

    client_0_connected = 0;
    client_1_connected = 0;
    client_last_active = 0;
    client_mode = 0;
}

TcpServer::~TcpServer() {
    if (this->tcpServer) {
        delete this->tcpServer;

        this->tcpServer = nullptr;
    }

    close_client_socket_0();
    close_client_socket_1();
}

int TcpServer::start_server(QString &ip, QString &port, bool disconn_event, bool cli_mode) {
    bool ok;
    bool addr_found = 0;

    QList<QHostAddress> ipAddressesList;
    QHostAddress ip_host(ip);

    disconnect_event = disconn_event;

    client_mode = cli_mode;

    if (!this->tcpServer) {
        this->tcpServer = new QTcpServer;
    }

    if (ip.isEmpty()) {
        qDebug() << "(tcp_server) Host ip not specified. Trying to guess ip ...";

        ipAddressesList = QNetworkInterface::allAddresses();

        // use the first non-localhost IPv4 address
        for (int i = 0; i < ipAddressesList.size(); ++i) {
            if (ipAddressesList.at(i) != QHostAddress::LocalHost && ipAddressesList.at(i).toIPv4Address()) {
                ip_host.setAddress(ipAddressesList.at(i).toString());

                qDebug() << "(tcp_server) IP found: " << ipAddressesList.at(i).toString();

                addr_found = 1;
                break;
            }
        }

        // if we did not find one, use IPv4 localhost
        if (!addr_found) {
            qDebug() << "(tcp_server) IP found: localhost";

            ip_host.setAddress(QHostAddress::LocalHost);
        }
    } else {
        if (ip == "localhost") {
            ip_host.setAddress("127.0.0.1");
        }
    }

    if (!this->tcpServer->listen(ip_host, port.toUInt(&ok, 10))) {
        qDebug() << "(tcp_server) Unable to start server!";

        return EXIT_FAILURE;
    }

    connect(this->tcpServer, &QTcpServer::newConnection, this, &TcpServer::on_new_connection);

    qDebug() << "(tcp_server) running on IP: " << this->tcpServer->serverAddress().toString() << "port: " << this->tcpServer->serverPort();
    qDebug() << "(tcp_server) disconnect event bridging: " << disconnect_event;

    return EXIT_SUCCESS;
}

void TcpServer::on_new_connection() {
    QTcpSocket *temp_client_sock;

    if (client_0_connected && client_1_connected) {
        qDebug() << "(tcp_server) New connection! (x)";
        qDebug() << "Aborting connection, 2 clients already connected!";

        temp_client_sock = this->tcpServer->nextPendingConnection();
        temp_client_sock->disconnectFromHost();
        temp_client_sock = nullptr;
    } else {
        if (!client_0_connected) {
            qDebug() << "(tcp_server) New connection! (0)";

            client_0_connected = 1;

            this->tcpSocketFirstClient = this->tcpServer->nextPendingConnection();

            if (this->tcpSocketFirstClient) {
                connect_signals(0);
            }
        } else if(!client_1_connected) {
            qDebug() << "(tcp_server) New connection! (1)";

            client_1_connected = 1;

            this->tcpSocketSecondClient = this->tcpServer->nextPendingConnection();

            if (this->tcpSocketSecondClient) {
                connect_signals(1);
            }
        }
    }
}

void TcpServer::connect_signals(int client_number){
    switch (client_number) {
    case 0:
        connect(this->tcpSocketFirstClient, SIGNAL(disconnected()), this->tcpSocketFirstClient, SLOT(deleteLater()));
        connect(this->tcpSocketFirstClient, SIGNAL(disconnected()), this, SLOT(on_closed_connection_0()));
        connect(this->tcpSocketFirstClient, SIGNAL(readyRead()), this, SLOT(on_ready_read_0()));
        break;
    case 1:
        connect(this->tcpSocketSecondClient, SIGNAL(disconnected()), this->tcpSocketSecondClient, SLOT(deleteLater()));
        connect(this->tcpSocketSecondClient, SIGNAL(disconnected()), this, SLOT(on_closed_connection_1()));
        connect(this->tcpSocketSecondClient, SIGNAL(readyRead()), this, SLOT(on_ready_read_1()));
        break;
    }
}

void TcpServer::disconnect_signals(int client_number) {
    switch (client_number) {
    case 0:
        if (this->tcpSocketFirstClient) {
            disconnect(this->tcpSocketFirstClient, SIGNAL(disconnected()), this->tcpSocketFirstClient, SLOT(deleteLater()));
            disconnect(this->tcpSocketFirstClient, SIGNAL(disconnected()), this, SLOT(on_closed_connection_0()));
            disconnect(this->tcpSocketFirstClient, SIGNAL(readyRead()), this, SLOT(on_ready_read_0()));

            this->tcpSocketFirstClient->disconnectFromHost();
            this->tcpSocketFirstClient = nullptr;
        }
        break;
    case 1:
        if (this->tcpSocketSecondClient) {
            disconnect(this->tcpSocketSecondClient, SIGNAL(disconnected()), this->tcpSocketSecondClient, SLOT(deleteLater()));
            disconnect(this->tcpSocketSecondClient, SIGNAL(disconnected()), this, SLOT(on_closed_connection_1()));
            disconnect(this->tcpSocketSecondClient, SIGNAL(readyRead()), this, SLOT(on_ready_read_1()));

            this->tcpSocketSecondClient->disconnectFromHost();
            this->tcpSocketSecondClient = nullptr;
        }
        break;
    }
}

void TcpServer::close_client_socket_0(){
    qDebug() << "(tcp_server) close_client_socket (0)";

    client_0_connected = 0;
    client_last_active = 1;

    disconnect_signals(0);
}

void TcpServer::on_closed_connection_0() {
    qDebug() << "(tcp_server) Connection closed! (0)";

    close_client_socket_0();

    if (disconnect_event) {
        close_client_socket_1();

        if (client_mode) {
            emit client_closed_the_connection();
        }
    }
}

void TcpServer::on_ready_read_0() {
    client_last_active = 0;

    QByteArray recv_msg = this->tcpSocketFirstClient->readAll();

    qDebug() << "(tcp_server) (0)";

    display_byte_array(recv_msg);

    if (client_mode) {
        emit send_to_remote_server(recv_msg);
    } else {
        send_to_client(recv_msg, 1);
    }
}

void TcpServer::close_client_socket_1() {
    qDebug() << "(tcp_server) close_client_socket (1)";

    client_1_connected = 0;
    client_last_active = 0;

    disconnect_signals(1);
}

void TcpServer::on_closed_connection_1() {
    qDebug() << "(tcp_server) Connection closed! (1)";

    close_client_socket_1();

    if (disconnect_event) {
        close_client_socket_0();

        if (client_mode) {
            emit client_closed_the_connection();
        }
    }
}

void TcpServer::on_ready_read_1() {
    client_last_active = 1;

    QByteArray recv_msg = this->tcpSocketSecondClient->readAll();

    qDebug() << "(tcp_server) (1)";

    display_byte_array(recv_msg);

    if (client_mode) {
        emit send_to_remote_server(recv_msg);
    } else {
        send_to_client(recv_msg, 0);
    }
}

void TcpServer::send_to_client(QByteArray &msg, int client_number) {
    switch(client_number){
    case 0:
        if (this->tcpSocketFirstClient) {
            this->tcpSocketFirstClient->write(msg);
        }
        break;
    case 1:
        if (this->tcpSocketSecondClient) {
            this->tcpSocketSecondClient->write(msg);
        }
        break;
    }
}

void TcpServer::on_recv_from_remote_server(QByteArray &msg) {
    send_to_client(msg, client_last_active);
}

void TcpServer::on_server_closed_the_connection() {
    if (disconnect_event && client_mode) {
        close_client_socket_0();
        close_client_socket_1();
    }
}