#ifndef MYLIST_H
#define MYLIST_H


class mylist
{
    public:
        mylist();
        mylist(mylist * d);
        mylist(int v);

        //funciones prueba
        mylist * getFront();
        mylist * getBack();


        int getSumNods();
        int getSize();
        void addList(mylist * d);

        void setHead(mylist * d);
        mylist * getHead();
        void setTail(mylist * d);
        mylist * getTail();



        //nuevas funciones para lista doblemente enlazada
        void insertList(mylist * n, int posicion);
        void deleteList(int posicion);

        void setValor(int v);//ya en el cpp
        int getValor();//ya en el cpp
        int getValorSiguientes();

        void setSig(mylist * s);//ya en el cpp
        mylist * getSig();//ya en el cpp

        void setAnt(mylist * s);
        mylist * getAnt();


        virtual ~mylist();



    protected:

    private:
        int cant;
        int valor;
        mylist * sig;
        mylist * ant;
        mylist * head;
        mylist * tail;
        mylist * temp1;
        mylist * temp2;
        mylist * temp3;
        mylist * temp4;
};

#endif // MYLIST_H
