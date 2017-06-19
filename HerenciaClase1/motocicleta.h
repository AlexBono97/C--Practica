#ifndef MOTOCICLETA_H
#define MOTOCICLETA_H
#include "vehiculorodante.h"


class Motocicleta : public VehiculoRodante
{
    public:
    Motocicleta();
        Motocicleta(int cp, int kmr, int tm, int ccomb, int col);
        VehiculoRodante * vr;

        void setTamanoMotor(int m);
        int getTamanoMotor();
        double getCostoKMRecorridos();

        void setCantComb(int ccomb);
        int getCantComb();

        void setcantidadPasajeros(int cp);
        void setKMRecorridos(int kmr);
        void setEjes(int ejes);
        void setPesoVehiculo(int peso);
        void setVelocidadMaxima(int vel);

        int getcantidadPasajeros();
        int getKMRecorridos();
        int getEjes();
        int getPesoVehiculo();
        int getVelocidadMaxima();

        //enum
        void setColor(int c);
        string getColor();

        virtual ~Motocicleta();

    protected:

    private:
        int tamanoMotor;
        int cantComb;
};

#endif // MOTOCICLETA_H
