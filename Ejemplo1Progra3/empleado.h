#ifndef EMPLEADO_H
#define EMPLEADO_H
#include "infopersona.h"

class Empleado
{
    public:

        Empleado();
        void setNombre_empleado(const char * c);
        char * getNombre_empleado();
        void setSalario(double c);
        double getSalario();
        void setDireccion_empleado(const char * c);
        char * getDireccion_empleado();
        void setCiudad_empleado(const char * c);
        char * getCiudad_empleado();
        void setProvincia_empleado(const char * c);
        char * getProvincia_empleado();
        void setCdPostal_empleado(long int c);
        long int getCdPostal_empleado();

        virtual ~Empleado();

    protected:

    private:
        char nombre_empleado[25];
        Infopersona empleado1;
        double salario;

};

#endif // EMPLEADO_H
