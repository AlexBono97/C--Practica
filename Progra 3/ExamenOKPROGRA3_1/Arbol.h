#ifndef ARBOL_H
#define ARBOL_H


class Arbol
{
    public:
        Arbol();
        Arbol(int a);
        void setAltura(int n);
        int getAltura();
        virtual int getValor()=0;
        void setSig(Arbol*n);
        Arbol* getSig();

    protected:

    private:
        int Altura;
        Arbol* siguiente;
};

#endif // ARBOL_H

