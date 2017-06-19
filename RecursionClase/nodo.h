#ifndef NODO_H
#define NODO_H


class nodo
{
    public:
        nodo();
        virtual ~nodo();

        nodo * getSiguiente();
        void setSiguiente(nodo * s);
        void addNodo(nodo * r);
        void ordenar(nodo * n1);
        void setValor(int n);
        int getValor();



    protected:

    private:
        int valor;
        int cant=0;
        nodo * sig;
        nodo * head;
        nodo * tail;
        nodo * temp1;
};

#endif // NODO_H
