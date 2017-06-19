#ifndef PINO_H
#define PINO_H
#include "arbol.h"


class Pino : public Arbol
{
    public:
        Pino();
        Pino(int altura, int edad);
        virtual ~Pino();

        int getValor();//ya

        void setAltura(int a);
        int getAltura();
        void setEdad(int e);
        int getEdad();


    protected:

    private:
        int edad;
};

#endif // PINO_H
