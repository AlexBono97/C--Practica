#ifndef COL_H
#define COL_H
#include "nodo.h"


class col
{
    public:
        col();
        col(nodo * d);
        int getSumNods();
        int getCant();

        void addNod(nodo * d);
        void setHead(nodo * d);
        nodo * getHead();
        void setTail(nodo * d);
        nodo * getTail();

        //nuevas funciones para lista doblemente enlazada
        void insertNodos(nodo * n,int posicion);
        void insertNodosSig(nodo * n, int posicion);
        void deleteNodos(int posicion);
        void deleteNodosinSig(nodo * n);
        void deleteNodoWith(int value);


        nodo * control;
        col * control2;

        void addCant(int c);
        virtual ~col();

    protected:

    private:
        nodo * head;//puntero variable
        nodo * tail;//puntero variable
        nodo * temp1;
        nodo * temp2;
        nodo * temp3;//puntero de prueba
        int cant;//contador con el que trabajaremos
};

#endif // COL_H
