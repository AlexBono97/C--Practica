#ifndef ULTIMALLAMADA_H
#define ULTIMALLAMADA_H
#include "contacto.h"

class ultimallamada
{
    public:
        ultimallamada();
        ultimallamada(contacto * n, ultimallamada * f);
        contacto * contactollamado;
        ultimallamada * siguienteUltimaLlamada;
        void add(ultimallamada * n);

        //probando
        ultimallamada * head;
        ultimallamada * gethead();

        //atributos
        void setSig(ultimallamada * s);
        ultimallamada * getSig();
        ultimallamada * sig;
        int cantLlamadas;
        virtual ~ultimallamada();


    protected:

    private:
};

#endif // ULTIMALLAMADA_H
