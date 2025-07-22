#pragma once

#include <QMainWindow>

class QSpinBox;
class QLabel;


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private slots:
    void spinValueChanged();

private:
    QSpinBox *spinBox;
    QLabel *outputLabel;
    QLabel *imageLabel;
    QVector<bool> bitVector;
};


