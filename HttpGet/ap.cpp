#include "ap.h"

CAp::CAp(QObject *parent) : QObject(parent)
{

}

CAp::~CAp()
{

}

QString CAp::getJson()
{
    CBluetoothAP ap;
    QString json=ap.getContext();
    ap.deleteLater();
    return json;
}

