#ifndef CBLUETOOTHAP_H
#define CBLUETOOTHAP_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QEventLoop>
#include <QDebug>

class CBluetoothAP : public QObject
{
    Q_OBJECT
public:
    explicit CBluetoothAP(QObject *parent = 0);
    ~CBluetoothAP();
private:
    QUrl m_url;
    QNetworkReply *m_pReply;
public:
   QString getContext();

signals:

public slots:
};

#endif // CBLUETOOTHAP_H
