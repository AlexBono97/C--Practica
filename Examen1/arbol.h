#ifndef ARBOL_H
#define ARBOL_H


class Arbol
{
    public:
        Arbol();
        Arbol(int a);
        virtual ~Arbol();

        void setSiguiente(Arbol * s);
        Arbol * getSiguiente();

        void setAltura(int a);
        int getAltura();

        virtual int getValor()=0;

    protected:

    private:
        int altura;
        Arbol * sig;
};

#endif // ARBOL_H
