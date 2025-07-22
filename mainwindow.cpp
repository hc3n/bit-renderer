#include "mainwindow.h"
#include "bitwidget.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QSpinBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Центральный виджет
    QWidget *central = new QWidget(this);
    setCentralWidget(central);

    // Основной layout
    QVBoxLayout *mainLayout = new QVBoxLayout(central);

    // Горизонтальный layout для "Период" + SpinBox
    QHBoxLayout *inputLayout = new QHBoxLayout();

    QLabel *labeltext = new QLabel("Период");
    inputLayout->addWidget(labeltext);

    spinBox = new QSpinBox();
    spinBox->setRange(1, 100000);
    spinBox->setValue(10000);
    inputLayout->addWidget(spinBox);

    mainLayout->addLayout(inputLayout);

    // Метка вывода
    outputLabel = new QLabel("Введите период");
    mainLayout->addWidget(outputLabel);

    // Подключение сигнала

    connect(spinBox, SIGNAL(valueChanged(int)), this, SLOT(spinValueChanged()));



    // Вывод отрисовщика сигнала. (картинки)
    imageLabel = new QLabel();
    imageLabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(imageLabel);

    bitWidget = new BitWidget(this);
    bitWidget->obrabotkaBin("/Users/timofey/Documents/renderer/renderer/test_long_1504.bin",bitVector);

}

void MainWindow::spinValueChanged() {
    int period = spinBox->value();
    outputLabel->setText("Текущий период: " + QString::number(period));

    QImage img = bitWidget ->risovalka(bitVector,period);
    imageLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    imageLabel->setPixmap(QPixmap::fromImage(img).scaled(imageLabel->size()));

}
