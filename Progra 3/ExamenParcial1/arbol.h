#ifndef ARBOL_H
#define ARBOL_H
#include "pino.h"

class Arbol
{
    public:
        Arbol();

        virtual ~Arbol();

        void setSiguiente(Arbol * a);
        Arbol * getSiguiente();

        virtual int valor()=0;

    protected:

    private:
        Arbol * sig;
};

#endif // ARBOL_H
