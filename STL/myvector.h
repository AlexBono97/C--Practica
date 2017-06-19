#ifndef MYVECTOR_H
#define MYVECTOR_H


class myvector
{
    public:
        myvector();
        myvector(myvector * d);
        myvector(int v);
        int getSumNods();
        int getSize();
        void addVector(myvector * d);

        void setHead(myvector * d);
        myvector * getHead();
        void setTail(myvector * d);
        myvector * getTail();



        //nuevas funciones para lista doblemente enlazada
        void insertVector(myvector * n, int posicion);
        void deleteVector(int posicion);

        void setValor(int v);//ya en el cpp
        int getValor();//ya en el cpp
        int getValorSiguientes();

        void setSig(myvector * s);//ya en el cpp
        myvector * getSig();//ya en el cpp

        void setAnt(myvector * s);
        myvector * getAnt();


        virtual ~myvector();



    protected:

    private:
        int cant;
        int valor;
        myvector * sig;
        myvector * ant;
        myvector * head;
        myvector * tail;
        myvector * temp1;
        myvector * temp2;
        myvector * temp3;
        myvector * temp4;
};

#endif // MYVECTOR_H
