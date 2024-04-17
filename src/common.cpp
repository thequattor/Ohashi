#include "common.h"

using namespace std;

void displayByteArray(QByteArray &hexData) {
    qDebug() << string(10, '-');  //<< "======================================";
    qDebug() << hexData.toHex(' ');
    qDebug() << string(10, '-');
    qDebug() << hexData;
    qDebug() << string(10, '-');
}
