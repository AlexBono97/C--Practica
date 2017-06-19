#ifndef CEDRO_H
#define CEDRO_H
#include "Arbol.h"


class Cedro : public Arbol
{
    public:
        Cedro();
        Cedro(int h,int g);
        int getGrosor();
        void setGrosor(int n);
        int getValor();

    protected:

    private:
        int grosor;
};

#endif // CEDRO_H

