#ifndef ARBOLEDA_H
#define ARBOLEDA_H
#include "Arbol.h"
#include "Fruta.h"
#include "iostream"

using namespace std;
class Arboleda
{
    public:
        Arboleda();
        void addArbol(Arbol*ar);
        int getCantidad();
        void deleteArbol(int po);
        Arbol* getPrimerArbol();
        Arbol* getUltimoArbol();
        int getValorArboleda();

    protected:

    private:
        int cantidad;
        Arbol* head;
        Arbol* tail;
};

#endif // ARBOLEDA_H

