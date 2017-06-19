#ifndef INFOPERSONA_H
#define INFOPERSONA_H
#include <string.h>

class InfoPersona
{
    public:
        InfoPersona();
        virtual ~InfoPersona();
        void setDireccion(const char * direccion);
        void setCiudad(const char * ciudad);
        void setProvincia(const char * provincia);
        void setCodigoPostal(const long int codigo);


        char* getDirecion();
        char* getCiudad();
        char* getProvincia();
        long int getCodigoPostal();

    protected:

    private:

        char direccion[25];
        char ciudad[20];
        char provincia[20];
        long int codigo_postal;
};

#endif // INFOPERSONA_H
