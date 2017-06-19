#include "mainwindow.h"
#include <QApplication>
#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <psapi.h>
#include "aplicacion.h"
#include "listaaplicaciones.h"
#include <iostream>


int main(int argc, char *argv[])
{


    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
