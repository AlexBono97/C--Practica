#ifndef BICICLETA_H
#define BICICLETA_H
#include "vehiculorodante.h"

class Bicicleta : public VehiculoRodante
{
    public:
    Bicicleta();
        Bicicleta(int cp,int kmr,int col);
        VehiculoRodante * vr;

        double getCostoKMRecorridos();

        void setcantidadPasajeros(int cp);
        void setKMRecorridos(int kmr);
        void setPesoVehiculo(int peso);
        void setVelocidadMaxima(int vel);

        int getcantidadPasajeros();
        int getKMRecorridos();
        int getPesoVehiculo();
        int getVelocidadMaxima();

        //enum
        void setColor(int c);
        string getColor();

        virtual ~Bicicleta();

    protected:

    private:

};

#endif // BICICLETA_H
