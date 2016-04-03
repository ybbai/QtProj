#ifndef CAP_H
#define CAP_H

#include <QObject>
#include "bluetoothAp.h"
class CAp : public QObject
{
    Q_OBJECT
public:
    explicit CAp(QObject *parent = 0);
    ~CAp();
public:
    Q_INVOKABLE QString getJson();

signals:

public slots:
};

#endif // CAP_H
