#ifndef PAQUETE_H
#define PAQUETE_H
#include <string>

using namespace std;


class paquete
{
    public:
        //atributos
        string nombre;
        string direccion;
        string ciudad;
        string estado;
        long codigopostal;
        int peso;
        int costoporonza;

        paquete();
        paquete(string nom, string dir, string city, string esta, long cd, int pe, int costo);

        //funciones
        double calcularCosto();
        virtual ~paquete();

    protected:

    private:
};

#endif // PAQUETE_H
