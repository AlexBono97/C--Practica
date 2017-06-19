#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <string.h>

class Empleado
{
    public:
        Empleado();
        virtual ~Empleado();

        void setNombre(const char * nombre);
        void setDireccion(const char * direccion);
        void setCiudad(const char * ciudad);
        void setProvincia(const char * provincia);
        void setCodigoPostal(const long int codigo);
        void setSalario(const double salario);

        char * getNombre();
        char* getDirecion();
        char* getCiudad();
        char* getProvincia();
        long int getCodigoPostal();
        double getSalario();



    protected:

    private:
        char nombre_empleado[25];
        char direccion[25];
        char ciudad[20];
        char provincia[20];
        long int codigo_postal;
        double salario;
};

#endif // EMPLEADO_H
