//<<#include <QDebug>
#include <QObject>
#include <QCoreApplication>

#include "tcp_server.h"
#include "tcp_client.h"

const int TCP_BRIDGE_VERSION = 1;
const int TCP_BRIDGE_SUBVERSION = 1;

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    //tcp_server *srv = nullptr;
    //tcp_client *client = nullptr;

    //TcpServer *srv = nullptr;
    //TcpClient *client = nullptr;

    QString paramName;
    QString hostIp;
    QString hostPort; //= "5533";
    QString remoteIp; // _ip_str;
    QString remotePort; //remote_port_str = "5533";

    bool disconnectEvent = false;
    bool clientMode = false;

    //qDebug() << "\n";
    //qDebug() << "TCP BROKER v" <<  << "." <<TCP_BRIDGE_SUBVERSION;
    //qDebug() << "\n";

    //args = a.arguments();

    QStringList args = app.arguments();

    args.takeFirst();

    //qDebug() << "args: " << args;

    int arg_sz = args.size();

    for (int i = 0; i < arg_sz; i++) {
        if (args.at(i).contains('-')) {
            paramName = args.at(i);
            paramName.section('-', 1, 1);

            if (paramName.contains('p') || paramName.contains("port")) {
                if (i+1 < arg_sz) {
                    hostPort = args.at(i+1);
                }
            } else if (paramName.contains('i') || paramName.contains("ip_addr")){
                if (i+1 < arg_sz) {
                    hostIp = args.at(i+1);
                }
            } else if (paramName.contains('d') || paramName.contains("disconnect_event")) {
                disconnectEvent = true;
            } else if (paramName.contains('c') || paramName.contains("client_mode")) {
                clientMode = true;
            } else if (paramName.contains('r') || paramName.contains("remote_server_ip")) {
                if (i+1 < arg_sz) {
                    remoteIp = args.at(i+1);
                }
            } else if (paramName.contains('o') || paramName.contains("remote_server_port")){
                if (i+1 < arg_sz) {
                    remotePort = args.at(i+1);
                }
            }
        }
    }

    if (args.isEmpty()) {
        qDebug() << "Usage: ./tcp_broker [OPTIONS] where [OPTIONS] is one of the following: ";
        qDebug() << "-p or -port [0 - 65535]: the port of the host server to listen to for incoming connections.";
        qDebug() << "-i or -ip_addr [xxx.xxx.xxx.xxx]: the ip address of the host server and its network interface.";
        qDebug() << "-c or -client_mode: enable a client that will connect to a remote server";
        qDebug() << "-r or -remote_server_ip: the ip address of the remote server (use with -c)";
        qDebug() << "-o or -remote_server_port: the port of the remote server (use with -c)";
        qDebug() << "-d or -disconnect_event: enable the bridging of a disconnect events from either of the hosts";

        return EXIT_FAILURE;
    }

    TcpServer *tcpServer = new TcpServer();

    //if (srv) {
    tcpServer->start_server(hostIp, hostPort, disconnectEvent, clientMode);
    //}

    if (clientMode) {
        TcpClient *tcpClient = new TcpClient();

        //if (client) {
        tcpClient->start_client(remoteIp, remotePort, disconnectEvent);
        //}

        //if (srv && client) {
        QObject::connect(tcpServer, SIGNAL(recv_from_remote_server(QByteArray &)), tcpServer, SLOT(on_recv_from_remote_server(QByteArray &)));
        QObject::connect(tcpServer, SIGNAL(send_to_remote_server(QByteArray &)), tcpClient, SLOT(on_send_to_remote_server(QByteArray &)));
        QObject::connect(tcpClient, SIGNAL(server_closed_the_connection()), tcpServer, SLOT(on_server_closed_the_connection()));
        QObject::connect(tcpServer, SIGNAL(client_closed_the_connection()), tcpClient, SLOT(on_client_closed_the_connection()));
        //}
    }

    return app.exec();
}
