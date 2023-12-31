#ifndef BYTECONVERTER_H
#define BYTECONVERTER_H

#include <QObject>

class ByteConverter : public QObject {
    Q_OBJECT
public:
    explicit ByteConverter(QObject* = nullptr);
public slots:
    void setDec(const QString&);
    void setHex(const QString&);
    void setBin(const QString&);
signals:
    void decChanged(const QString&);
    void hexChanged(const QString&);
    void binChanged(const QString&);
};

#endif
