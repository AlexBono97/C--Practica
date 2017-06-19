#ifndef PAQUETENOCTURNO_H
#define PAQUETENOCTURNO_H
#include "paquete.h"
#include <string>

using namespace std;


class paquetenocturno : public paquete
{
    public:
        //atributos
        int cobronocturno;
        paquetenocturno();
        paquetenocturno(int cobron,string n, string dir, string ciu, string esta, long cd, int pe, int costo);
        virtual ~paquetenocturno();
        //funciones
        double calcularcostonocturno();

    protected:

    private:
};

#endif // PAQUETENOCTURNO_H
