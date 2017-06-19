#ifndef CEDRO_H
#define CEDRO_H
#include "arbol.h"

class Cedro : public Arbol
{
    public:
        Cedro();
        Cedro(int altura, int grosor);
        virtual ~Cedro();

        int getValor();

        void setAltura(int a);
        int getAltura();
        void setGrosor(int g);
        int getGrosor();

    protected:

    private:
        int grosor;
};

#endif // CEDRO_H
