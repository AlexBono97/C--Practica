#ifndef CLIENTE_H
#define CLIENTE_H
#include "infopersona.h"


class cliente
{
    public:
        cliente();
        void setNombre_cliente(const char * c);
        char * getNombre_cliente();
        void setSaldo(double c);
        double getSaldo();

        void setDireccion_cliente(const char * c);
        char * getDireccion_cliente();
        void setCiudad_cliente(const char * c);
        char * getCiudad_cliente();
        void setProvincia_cliente(const char * c);
        char * getProvincia_cliente();
        void setCdPostal_cliente(long int c);
        long int getCdPostal_cliente();




    protected:

    private:
        char nombre_cliente[25];
        Infopersona cliente1;
        double saldo;
};

#endif // CLIENTE_H
