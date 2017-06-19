#ifndef VEHICULORODANTE_H
#define VEHICULORODANTE_H
#include <string>

using namespace std;

class VehiculoRodante
{
    public:
        VehiculoRodante();
        VehiculoRodante(int cp, int kmr, int col);
        virtual ~VehiculoRodante();

    //sets y gets
        void setcantidadPasajeros(int cp);//ya implementado
        void setKMRecorridos(int kmr);//ya implementado
        void setEjes(int ejes);//ya implementado
        void setPesoVehiculo(int peso);//ya implementado
        void setVelocidadMaxima(int vel);//ya implementado
        void setColor(int c);//ya implementado

        int getcantidadPasajeros();//ya implementado
        int getKMRecorridos();//ya implementado
        int getEjes();//ya implementado
        int getPesoVehiculo();//ya implementado
        int getVelocidadMaxima();//ya implementado
        string getColor();//ya implementado


        enum color {Azul, Amarillo, Verde, Negro, Gris, Blanco, Rojo, Plateado, Cafe};

        virtual double getCostoKMRecorridos()=0;// es =0 porque no esta implementando

    protected:

    private:
        string color2;
        int cantidadPasajeros;
        int KMrecorridos;
        int ejes;
        int pesoVehiculo;
        int VelocidadMaxima;

};

#endif // VEHICULORODANTE_H
