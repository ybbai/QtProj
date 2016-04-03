#include <QApplication>
#include <QQmlApplicationEngine>
#include <qqml.h>
#include "cpps/bluetooth/bluetoothLabel.h"
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    qmlRegisterType<CBluetoothLabel>("QmlBluetoothLabel",1,0,"QmlBluetoothLabel");
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/qmls/main.qml")));

    return app.exec();
}
