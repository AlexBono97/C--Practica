#include "listavisual.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ListaVisual w;
    w.show();

    return a.exec();
}
