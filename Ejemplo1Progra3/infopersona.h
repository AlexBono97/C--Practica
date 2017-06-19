#ifndef INFOPERSONA_H
#define INFOPERSONA_H


class Infopersona
{
    public:
        void setDireccion(const char * c);
        void setCiudad(const char * c);
        void setProvincia(const char * c);
        void setCdPostal(long int c);
        char * getDireccion();
        char * getCiudad();
        char * getProvincia();
        long int getCdPostal();

        Infopersona();
        virtual ~Infopersona();

    protected:

    private:
        char direccion[25];
        char ciudad[20];
        char provincia[20];
        long int codigo_postal;
};

#endif // INFOPERSONA_H
