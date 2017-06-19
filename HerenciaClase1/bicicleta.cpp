#include "bicicleta.h"

Bicicleta::Bicicleta()
{
    //ctor
}
Bicicleta::Bicicleta(int cp, int kmr, int col) : VehiculoRodante(cp,kmr,col)
{

}

double Bicicleta::getCostoKMRecorridos()
{
    double costoKMRecorridos=0;
    return costoKMRecorridos;
}


//sets heredados
void Bicicleta::setcantidadPasajeros(int c)
{
    vr->setcantidadPasajeros(c);
}

void Bicicleta::setKMRecorridos(int c)
{
    vr->setKMRecorridos(c);
}

void Bicicleta::setPesoVehiculo(int p)
{
    vr->setPesoVehiculo(p);
}

void Bicicleta::setVelocidadMaxima(int j)
{
    vr->setVelocidadMaxima(j);
}

//Gets heredados
int Bicicleta::getcantidadPasajeros()
{
    return vr->getcantidadPasajeros();
}

int Bicicleta::getKMRecorridos()
{
    return vr->getKMRecorridos();
}

int Bicicleta::getPesoVehiculo()
{
    return vr->getPesoVehiculo();
}

int Bicicleta::getVelocidadMaxima()
{
    return vr->getVelocidadMaxima();
}

//Colores
void Bicicleta::setColor(int c)
{
    vr->setColor(c);
}

string Bicicleta::getColor()
{
    return vr->getColor();
}

Bicicleta::~Bicicleta()
{
    //dtor
}
