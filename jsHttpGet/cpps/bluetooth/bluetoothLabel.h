#ifndef CBLUETOOTHLABEL_H
#define CBLUETOOTHLABEL_H

#include <qdebug.h>
#include <QObject>
#include <QPointF>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>

#include <QApplication>
#include <QFile>

static QString getQString(QJsonObject jsonObj, QString key){
    QJsonValue jsonValue= jsonObj.contains(key)? jsonObj.take(key): NULL;
    if(jsonValue == NULL)
        return "";

    return jsonValue.toString();

}
static double getDouble(QJsonObject jsonObj, QString key){
    QJsonValue jsonValue= jsonObj.contains(key)? jsonObj.take(key): NULL;
    if(jsonValue == NULL)
        return 0.0;

    return jsonValue.toDouble();
}
static int getInt(QJsonObject jsonObj, QString key){
    QJsonValue jsonValue= jsonObj.contains(key)? jsonObj.take(key): NULL;
    if(jsonValue == NULL)
        return 0;

    return jsonValue.toInt();
}
static QJsonArray getJsonArray(QJsonObject jsonObj, QString key){
    QJsonValue jsonValue = jsonObj.contains(key) ? jsonObj.take(key) : NULL;

    return jsonValue.toArray();
}
static QJsonObject getJsonObj(QJsonObject jsonObj, QString key){
    QJsonValue jsonValue = jsonObj.contains(key) ? jsonObj.take(key) : NULL;
    return jsonValue.toObject();
}


/*******************************/
//   all    key
/*******************************/
struct BluetoothKey{
    QString
    code,
    command,//QString
    message,
    responseTS,
    status,
    tags, //JsonArray
    areaId,
    areaName,
    color,
    coordinateSystemId,
    coordinateSystemName,
    covarianceMatrix,//JsonArray
    id,
    name,
    position,//JsonArray
    positionAccuracy,
    positionTS,
    smoothedPosition,//JsonArray
    zones,//JsonArray
    version;

    BluetoothKey(){
        code = "code";
        command = "command";
        message = "message";
        responseTS = "responseTS";
        status = "status";
        tags = "tags";
        areaId = "areaId";
        areaName = "areaName";
        color = "color";
        coordinateSystemId = "coordinateSystemId";
        coordinateSystemName = "coordinateSystemName";
        covarianceMatrix = "covarianceMatrix";
        id = "id";
        name = "name";
        position = "position";
        positionAccuracy = "positionAccuracy";
        positionTS = "positionTS";
        smoothedPosition = "smoothedPosition";
        zones = "zones";
        version = "version";
    }
};


/*******************************/
//       Bluetooth Entity
/*******************************/
struct EmpBluetooth{
    QString
    areaId,
    areaName,
    color,
    coordinateSystemId,
    coordinateSystemName,
    id,
    name,
    zonesId,
    zonesName;

    QPointF
    point ,
    smoothedPoint;//平滑滤波后的坐标 单位：米

    double positionTS,positionAccuracy,covarianceMatrix[4];

    EmpBluetooth(){
        id = areaId = areaName =  color = coordinateSystemName =
                zonesId = zonesName = "";

        positionTS = positionAccuracy = 0.0f;

        covarianceMatrix[0] = 0.0f;
        covarianceMatrix[1] = 0.0f;
        covarianceMatrix[2] = 0.0f;
        covarianceMatrix[3] = 0.0f;

        point = smoothedPoint = QPointF(0.0f,0.0f);

    }

};

class CBluetoothLabel : public QObject
{
    Q_OBJECT
public:
    explicit CBluetoothLabel(QObject *parent = 0);
    ~CBluetoothLabel();


private:
    BluetoothKey m_key;
    std::vector<EmpBluetooth> m_bluetoothLabels;

public:
    Q_INVOKABLE void setBluetoothLabels(QByteArray json);

signals:
    void sigReadBluetoothLabels(std::vector<EmpBluetooth> bluetoothLabels);
    void sigReadBluetoothLabel(EmpBluetooth bluetoothLabel);
    void sigReadDone();
signals:
    void sigErr(QString err);

public slots:
};

#endif // CBLUETOOTHLABEL_H
