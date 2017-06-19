#ifndef LISTADUENDE_H
#define LISTADUENDE_H
#include "enfermedad.h"


class Listaduende
{
    public:
        Listaduende();

        virtual ~Listaduende();

        void infoReemplazados();
        void infoHistorial();
        void enfermarDuende(enfermedad * e);

        void setSig(Listaduende * s);//ya en el cpp
        Listaduende * getSig();//ya en el cpp

        void setAnt(Listaduende * s);
        Listaduende * getAnt();



    protected:

    private:
};

#endif // LISTADUENDE_H
