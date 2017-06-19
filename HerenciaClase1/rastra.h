#ifndef RASTRA_H
#define RASTRA_H
#include "vehiculorodante.h"


class Rastra : public VehiculoRodante
{
    public:
        Rastra();
        Rastra(int cp, int kmr, int tm, int ccomb, int col);
        VehiculoRodante * vr;

        void setTamanoMotor(int m);//ya implementado
        int getTamanoMotor();//ya implementado
        double getCostoKMRecorridos();

        void setCantComb(int ccomb);
        int getCantComb();

        void setcantidadPasajeros(int cp);//ya implementado
        void setKMRecorridos(int kmr);//ya implementado
        void setEjes(int ejes);//ya implementado
        void setPesoVehiculo(int peso);//ya implementado
        void setVelocidadMaxima(int vel);//ya implementado

        int getcantidadPasajeros();//ya implementado
        int getKMRecorridos();//ya implementado
        int getEjes();//ya implementado
        int getPesoVehiculo();//ya implementado
        int getVelocidadMaxima();//ya implementado

        //enum
        void setColor(int c);
        string getColor();






        virtual ~Rastra();

    protected:

    private:
        int tamanoMotor;
        int cantComb;
};

#endif // RASTRA_H
