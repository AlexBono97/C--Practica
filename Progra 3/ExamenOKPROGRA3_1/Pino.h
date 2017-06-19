#ifndef PINO_H
#define PINO_H
#include "Arbol.h"

class Pino : public Arbol
{
    public:
        Pino();
        Pino(int h,int e);
        int getEdad();
        void setEdad(int e);
        int getValor();

    protected:

    private:
        int edad;
};

#endif // PINO_H
