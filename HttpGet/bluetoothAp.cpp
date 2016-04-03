#include "bluetoothAp.h"

CBluetoothAP::CBluetoothAP(QObject *parent) : QObject(parent)
{
    m_pReply=NULL;
    m_url=QUrl("http://192.168.123.124:8080/qpe/getHAIPLocation?maxAge=30000");

}

CBluetoothAP::~CBluetoothAP()
{
}

QString CBluetoothAP::getContext()
{
    QNetworkAccessManager accMage;
    QEventLoop loop;
    m_pReply = accMage.get(QNetworkRequest(m_url));
    connect(m_pReply,SIGNAL(finished()),&loop,SLOT(quit()));
    loop.exec();

    QString code=m_pReply->readAll();
    m_pReply->deleteLater();
    //qDebug()<<code;
    return code;
}

