#ifndef NODO_H
#define NODO_H


class nodo
{
    public:
        nodo();//constructor default
        nodo(int v);//constructor 2
        nodo(int v, nodo * s);//constructor 3

        void setValor(int v);//ya en el cpp
        int getValor();//ya en el cpp
        int getValorSiguientes();

        void setSig(nodo * s);//ya en el cpp
        nodo * getSig();//ya en el cpp

        void setAnt(nodo * s);
        nodo * getAnt();


        virtual ~nodo();

    protected:

    private:
        int valor;
        nodo * sig;
        nodo * ant;
};

#endif // NODO_H
