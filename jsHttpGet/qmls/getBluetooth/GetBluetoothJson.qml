import QtQuick 2.0

import "ajax.js" as Ajax;
import QmlBluetoothLabel 1.0
Rectangle {

    property int timer_interval: 500 ;
    signal sigBluetoothDataReady(var jsonData);

    QmlBluetoothLabel{
        id: blBluetoothLabel ;
        Component.onCompleted: blTimer.start() ;
    }
    Timer{
        id: blTimer ;
        interval: timer_interval ;
        running: true ;
        repeat: true ;
        onTriggered: fnGetBluetoothLablsJson();

    }


    function fnSetInterval(interval){
        timer_interval = interval;
    }

    function fnGetBluetoothLablsJson(){
        Ajax.get(
              function(jsonData,failure){
                blBluetoothLabel.setBluetoothLabels(jsonData);
                sigBluetoothDataReady(JSON.parse(jsonData)) ;
        });
    }
}

