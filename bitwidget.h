#include <QWidget>
#include <QFile>
#include <QImage>
#include <QVector>
#include <QString>
#include <QBitArray>

class BitWidget: public QWidget{
    Q_OBJECT

public:
    explicit BitWidget(QWidget *parent = nullptr);

    //               (путь к файлу, передача по ссылке битов)
    void obrabotkaBin(const QString &filename,QVector<bool> &bitVector);

    QImage risovalka(const QVector<bool> &bitVector,int period);

private:
    QImage image;

};
