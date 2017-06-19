#ifndef PAQUETEDOSDIAS_H
#define PAQUETEDOSDIAS_H
#include "paquete.h"
#include <string>

using namespace std;


class paquetedosdias : public paquete
{
    public:
        //Atributos
        int cobrodosdias;
        paquetedosdias();
        paquetedosdias(int c, string nom, string dir, string ciu, string esta, long cd, int pe, int costo);

        //funciones
        double calcularCostodosdias();
        virtual ~paquetedosdias();

    protected:

    private:
};

#endif // PAQUETEDOSDIAS_H
