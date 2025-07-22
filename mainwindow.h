#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QSpinBox;
class QLabel;
class BitWidget; // forward declaration

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

    BitWidget *bitWidget;
    QVector<bool> bitVector;

};

#endif // MAINWINDOW_H
