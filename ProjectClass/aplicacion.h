#ifndef APLICACION_H
#define APLICACION_H
#include <iostream>
#include <QString>
using namespace std;

class Aplicacion
{
public:
    Aplicacion();
    Aplicacion(QString n, long int i);
            virtual ~Aplicacion();

            Aplicacion * next, *ant;
            void setNext(Aplicacion * n);
            Aplicacion* getNext();
            void setAnt(Aplicacion * n);
            Aplicacion* getAnt();
             QString name;
             long int id;
             Aplicacion* head, *tail;
};

#endif // APLICACION_H
