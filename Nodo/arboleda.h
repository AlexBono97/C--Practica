#ifndef ARBOLEDA_H
#define ARBOLEDA_H
#include "arbol.h"



class Arboleda
{
    public:
        Arboleda();
        virtual ~Arboleda();

        //Funciones
        void addArbol(Arbol * s);
        int getCantidad();
        void deleteArbol(int pos);
        arbol * getUltimoArbol();
        arbol * getPrimerArbol();
        int getValorArboleda();

    protected:

    private:
};

#endif // ARBOLEDA_H
