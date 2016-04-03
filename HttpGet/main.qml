import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import QmlBluetoothAP 1.0
Window {
    title: qsTr("Hello World")
    width: 640
    height: 480
    visible: true
    QmlBluetoothAP{
        id:mAp
        Component.onCompleted: {
            mTimer.start();
        }
    }
    Timer{
        id: mTimer;
        interval: 10;
        repeat: true;
        onTriggered: {
            var jsonAp=JSON.parse(mAp.getJson());
            for(var item in jsonAp){
                console.log(jsonAp[item]["positionX"].toString());
            }
        }
    }
}
