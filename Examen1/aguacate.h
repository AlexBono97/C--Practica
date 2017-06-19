#ifndef AGUACATE_H
#define AGUACATE_H
#include "arbol.h"


class Aguacate : public Arbol
{
    public:
        Aguacate();
        Aguacate(int altura);
        virtual ~Aguacate();

        int getValor();

        int getAltura();
        void setAltura(int a);

    protected:

    private:
        int fruta;
};

#endif // AGUACATE_H
