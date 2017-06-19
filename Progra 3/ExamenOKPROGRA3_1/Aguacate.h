#ifndef AGUACATE_H
#define AGUACATE_H
#include "Fruta.h"
#include "Arbol.h"


class Aguacate : public Arbol
{
    public:
        Aguacate();
        Aguacate(int n, int m);
        virtual ~Aguacate();
        int getCant();
        int getValor();
        void setFruta(int pe,int pa);
        int cant;

    protected:

    private:
        Fruta*frct;
};

#endif // AGUACATE_H
