import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2

import "getBluetooth"
Window {
    title: qsTr("Hello World")
    width: 640
    height: 480
    visible: true
    property bool pause: false;

    GetBluetoothJson{
        id: mGetBluetoothLabel ;
        //Component.onCompleted: fnSetInterval(5);
    }

}
