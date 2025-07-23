#include "bittransformer.h"
#include <QDebug>
#include <QFile>


BitTransformer::BitTransformer(QObject *parent)
    : QObject(parent)
{
}

QVector<bool> BitTransformer::loadBitsFromBinary(const QString &filename)
{
    QVector<bool> bitVector;
    bitVector.clear();

    QFile filebin(filename);
    if (!filebin.open(QIODevice::ReadOnly)) {
        qWarning() << filebin.errorString();
        return bitVector;
    }

    QByteArray byteArray = filebin.readAll();

    filebin.close();

        for (char byte : byteArray) {
            for(int i = 7; i >= 0 ; --i) {
                bool bit = (byte >> i) & 1;
                bitVector.append(bit);
            }
        }
        return bitVector;
};

QImage BitTransformer::bitVectorToImage(const QVector<bool> &bitVector,int period)
{

    /* Вводим totalSize для того, чтобы увеличить общий размер рисунка
    * и избежать потери данных. Заполняем остаток черными пикселями.
    * Картинка QImage будет иметь правильные размеры */

    int size = bitVector.size();
    int remainder = size % period;
    int totalSize = size;
    if (remainder != 0)
        totalSize = (period - remainder) + size;

    int height = totalSize / period;
    int width = period;

    QImage image(width,height,QImage::Format_RGB32);
    QRgb green = qRgb(0,255,0);
    QRgb black = qRgb(0,0,0);
    QRgb *pixels = reinterpret_cast<QRgb*>(image.bits());
    QRgb *p = pixels;

    for(int i=0; i<totalSize;++i,++p)
    {
        if (i < size)
            *p =bitVector[i] ? green : black;
        else
            *p = black;
    }

    return image;
};
