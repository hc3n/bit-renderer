#pragma once

#include <QObject>
#include <QImage>
#include <QVector>
#include <QString>


class BitTransformer : public QObject
{
    Q_OBJECT

public:
    explicit BitTransformer(QObject *parent = nullptr);
    //               (путь к файлу, передача по ссылке битов)
    static QVector<bool> loadBitsFromBinary(const QString &filename);
    static QImage bitVectorToImage(const QVector<bool> &bitVector,int period);

};


