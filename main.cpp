#include "mainwindow.h"
#include "dialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Dialog d;
    d.show();

    if(d.exec()==QDialog::Accepted){
        MainWindow w(nullptr,d.socket,d.username);
        w.show();
        return a.exec();
    }

    return 0;
}
