#include <QApplication>
#include "mainwindow.h"


int main(int argc, char *argv[]) {

    QApplication app(argc, argv);
    MainWindow window;
    window.setWindowTitle("Битовый отрисовщик");
    window.resize(700, 250);
    window.show();
    return app.exec();
}
