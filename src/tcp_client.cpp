#include "tcp_client.h"

TcpClient::TcpClient() {
    this->clientSock = nullptr;
}

TcpClient::~TcpClient() {
    disconnectSignals();
}

void TcpClient::disconnectSignals() {
    if ( this->clientSock) {
        disconnect(  this->clientSock, SIGNAL(connected()), this, SLOT(on_connected()));
        disconnect(  this->clientSock, SIGNAL(disconnected()), this->clientSock, SLOT(deleteLater()));
        disconnect(this->clientSock, SIGNAL(disconnected()), this, SLOT(on_closed_connection()));
        disconnect(this->clientSock, SIGNAL(readyRead()), this, SLOT(on_ready_read()));
        disconnect(this->clientSock, SIGNAL(errorOccurred(QAbstractSocket::SocketError)), this, SLOT(on_error(QAbstractSocket::SocketError)));

        this->clientSock->disconnectFromHost();
        this->clientSock = nullptr;
    }
}

int TcpClient::start_client(QString &ip, QString &port, bool disconn_event) {
    bool ok;

    if (!this->clientSock) {
        this->clientSock = new QTcpSocket(this);

        connect(this->clientSock, SIGNAL(connected()), this, SLOT(on_connected()));
        connect(this->clientSock, SIGNAL(disconnected()), this->clientSock, SLOT(deleteLater()));
        connect(this->clientSock, SIGNAL(disconnected()), this, SLOT(on_closed_connection()));
        connect(this->clientSock, SIGNAL(readyRead()), this, SLOT(on_ready_read()));
        connect(this->clientSock, SIGNAL(errorOccurred(QAbstractSocket::SocketError)), this, SLOT(on_error(QAbstractSocket::SocketError)));

        if (ip.isEmpty()) {
            qDebug() << "(tcp_client) No remote ip specified! Using localhost ...";

            ip = "127.0.0.1";
        }

        if (port.isEmpty()) {
            qDebug() << "(tcp_client) No remote port specified! Using 5533 ...";
            ip = "127.0.0.1";
        }

        this->clientSock->connectToHost(ip, port.toUInt(&ok, 10));
    }

    this->disconnectEvent = disconn_event;

    return EXIT_SUCCESS;
}

void TcpClient::on_connected() {
    qDebug() << "(tcp_client) Connected to remote server!";
}

void TcpClient::on_closed_connection() {
    qDebug() << "(tcp_client) Connection closed!";

    if (this->disconnectEvent) {
        emit server_closed_the_connection();
    }
}

void TcpClient::on_ready_read() {
    QByteArray recv_msg = this->clientSock->readAll();

    qDebug() << "(tcp_client) ";
    displayByteArray(recv_msg);

    emit recv_from_remote_server(recv_msg);
}

void TcpClient::on_error(QAbstractSocket::SocketError err) {
    qDebug() << "(tcp_client) Remote server err: "<<err;
}

void TcpClient::on_send_to_remote_server(QByteArray &msg) {
    this->clientSock->write(msg);
}

void TcpClient::on_client_closed_the_connection() {
    disconnectSignals();
}
