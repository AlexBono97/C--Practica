#ifndef CLIENTE_H
#define CLIENTE_H
#include <string.h>

class Cliente
{
    public:
        Cliente();
        virtual ~Cliente();
        void setNombre(const char * nombre);
        void setDireccion(const char * direccion);
        void setCiudad(const char * ciudad);
        void setProvincia(const char * provincia);
        void setCodigoPostal(const long int codigo);
        void setSaldo(const double saldo);

        char * getNombre();
        char* getDirecion();
        char* getCiudad();
        char* getProvincia();
        long int getCodigoPostal();
        double getSaldo();


    protected:

    private:
        char nombre_cliente[25];
        char direccion[25];
        char ciudad[20];
        char provincia[20];
        long int codigo_postal;
        double saldo;

};

#endif // CLIENTE_H
