/*
Используем bits(), наш период в спинбоксе это количество пикселей в одной строчке
Отрисовываем 1 бит = 1 пиксель
*/
#include <QApplication>
#include "mainwindow.h"
#include "bitwidget.h"



int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MainWindow window;


    window.setWindowTitle("Битовый отрисовщик");
    window.resize(700, 250);
    window.show();

    return app.exec();
}
