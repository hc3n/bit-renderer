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
    int height = bitVector.size() / period;
    int width = period;

    /* format_indexed8 8 бит = 1 байт */
    QImage image(width,height,QImage::Format_Indexed8);
    uchar *data = image.bits(); // data - указатель на первый пиксель в памяти
    // используем два цвета через индексированную палитру (надо поменять)
    image.setColor(0,qRgb(0,0,0)); // black
    image.setColor(1,qRgb(0,255,0)); // green

    for(int i=0; i<bitVector.size();++i)
    {
        data[i] = bitVector[i] ? 1 : 0;
    }

    return image;
};
