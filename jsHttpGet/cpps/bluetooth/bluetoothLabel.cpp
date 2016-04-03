#include "bluetoothLabel.h"

CBluetoothLabel::CBluetoothLabel(QObject *parent) : QObject(parent)
{

}

CBluetoothLabel::~CBluetoothLabel()
{

}

void CBluetoothLabel::setBluetoothLabels(QByteArray json)
{
    QFile inputFile(QApplication::applicationDirPath() + QString::fromLocal8Bit("/output.txt"));
    inputFile.open(QIODevice::ReadWrite);
    QString b ;//= inputFile.readAll()
    inputFile.readAll();

    //     QByteArray line = inputFile.readAll()+json;
    //    inputFile.write(line.toStdString().c_str());
    //    inputFile.close();

    m_bluetoothLabels.clear();
    QJsonParseError json_error;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(json, &json_error);

    QJsonObject labelObj, jsonObj, zoneObj;
    QJsonArray point2f, smoothedPoint2f, zoneArr2S, pointArr4f, tagsArr;

    if(json_error.error == QJsonParseError::NoError) {
        jsonObj =  jsonDoc.object();
        tagsArr = getJsonArray(jsonObj, m_key.tags);

        for(int i = 0; i < tagsArr.count(); i++){

            labelObj = tagsArr[i].toObject();
            EmpBluetooth bluetoothLabel;
            bluetoothLabel.id = getQString(labelObj, m_key.id);
            bluetoothLabel.areaId = getQString(labelObj, m_key.areaId);
            bluetoothLabel.areaName = getQString(labelObj, m_key.areaName);
            bluetoothLabel.color = getQString(labelObj, m_key.color);
            bluetoothLabel.coordinateSystemId
                    = getQString(labelObj, m_key.coordinateSystemId);
            bluetoothLabel.coordinateSystemName
                    = getQString(labelObj, m_key.coordinateSystemName);
            bluetoothLabel.name = getQString(labelObj, m_key.name);
            bluetoothLabel.positionAccuracy
                    = getDouble(labelObj, m_key.positionAccuracy);
            bluetoothLabel.positionTS = getDouble(labelObj, m_key.positionTS);

            smoothedPoint2f = getJsonArray(labelObj, m_key.smoothedPosition);
            bluetoothLabel.smoothedPoint =
                    smoothedPoint2f.count() > 0
                    ? QPointF(smoothedPoint2f[0].toDouble(), smoothedPoint2f[1].toDouble())
                : QPointF(0,0);

            point2f = getJsonArray(labelObj, m_key.position);
            bluetoothLabel.point =
                    point2f.count() >0
                    ? QPointF(point2f[0].toDouble(),point2f[1].toDouble())
                : QPointF(0,0);

            zoneArr2S = getJsonArray(labelObj, m_key.zones);
            if(zoneArr2S.count() > 0){
                zoneObj = zoneArr2S[0].toObject();
                bluetoothLabel.zonesId = getQString(zoneObj, m_key.id);
                bluetoothLabel.zonesName = getQString(zoneObj, m_key.name);
            }

            pointArr4f = getJsonArray(labelObj, m_key.covarianceMatrix);
            bluetoothLabel.covarianceMatrix[0] = pointArr4f[0].toDouble();
            bluetoothLabel.covarianceMatrix[1] = pointArr4f[1].toDouble();
            bluetoothLabel.covarianceMatrix[2] = pointArr4f[2].toDouble();
            bluetoothLabel.covarianceMatrix[3] = pointArr4f[3].toDouble();

            b+="id:"+bluetoothLabel.id
                    + "name:"+bluetoothLabel.name
                    + "X:"+QString::number(bluetoothLabel.smoothedPoint.x())
                    +  "Y:"+QString::number(bluetoothLabel.smoothedPoint.y());

            emit sigReadBluetoothLabel(bluetoothLabel);
            m_bluetoothLabels.push_back(bluetoothLabel);
        }
        emit sigReadBluetoothLabels(m_bluetoothLabels);
    }
    else
        emit sigErr(QString::fromLocal8Bit("JSON数据解析错误:")
                    +json_error.errorString()+"\n原数据：" + json);


    inputFile.write( json.toStdString().c_str());
    inputFile.close();

    emit sigReadDone();

    qDebug()<<"X:"<<QString::number(m_bluetoothLabels[0].smoothedPoint.x())
            <<"Y:"<<QString::number(m_bluetoothLabels[0].smoothedPoint.y());
}

