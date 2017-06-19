#ifndef FRUTA_H
#define FRUTA_H
#include "aguacate.h"


class fruta : public Aguacate
{
    public:
        fruta();
        virtual ~fruta();

        int getValorfrutas();//recorre y suma el total almacenanado
        void setValorfrutas();//agrega un valor a cada fruta nueva

        //funciones de manejo de la lista de frutas
        void addFruta(fruta * f);//ya implementado
        void setSig(fruta * f);//ya implementado
        fruta * getSig();//ya implementado

    protected:

    private:

        int cant=0;
        int tamano;
        int peso;
        int valorfrutas;
        fruta * sigui;
        fruta * head;
        fruta * tail;
        fruta * temp1;
        fruta * temp2;
        fruta * temp3;
        fruta * temp4;
};

#endif // FRUTA_H
