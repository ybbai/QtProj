#include <QApplication>
#include <QQmlApplicationEngine>
#include <qqml.h>
#include "ap.h"
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    qmlRegisterType<CAp>("QmlBluetoothAP",1,0,"QmlBluetoothAP");
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
