#ifndef LISTAAPLICACIONES_H
#define LISTAAPLICACIONES_H
#include "aplicacion.h"
#include <QMainWindow>
#include <QListWidgetItem>
#include <QStringList>
#include <QString>
class ListaAplicaciones
{
public:
    ListaAplicaciones();
    virtual ~ListaAplicaciones();
    void addApp(Aplicacion* a);
    void printList();
    Aplicacion* head, *tail;
    int cont;
    bool verificar(Aplicacion* a);
    QStringList* toArray();
    long int getID(QString nam);
};

#endif // LISTAAPLICACIONES_H
