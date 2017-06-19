#ifndef FRUTA_H
#define FRUTA_H


class Fruta
{
    public:
        Fruta();
        Fruta(int w,int m);
        void setPeso(int w);
        void setTamano(int t);
        int getPeso();
        int getTamano();
        Fruta* getSig();
        void setSig(Fruta*sg);


    protected:

    private:
        int peso;
        int tamano;
        Fruta*siguiente;
};

#endif // FRUTA_H

