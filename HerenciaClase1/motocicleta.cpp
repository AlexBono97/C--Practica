#include "motocicleta.h"

Motocicleta::Motocicleta()
{
    //ctor
}

Motocicleta::Motocicleta(int cp, int kmr, int tm, int cantComb, int col) : VehiculoRodante(cp,kmr,col)
{
    setTamanoMotor(tm);
    setCantComb(cantComb);
}

void Motocicleta::setTamanoMotor(int m)
{
    tamanoMotor=m;
}

int Motocicleta::getTamanoMotor()
{
    return tamanoMotor;
}

double Motocicleta::getCostoKMRecorridos()
{
    double k=VehiculoRodante::getKMRecorridos();

    double costoKMRecorridos=(k/cantComb)*90;
    return costoKMRecorridos;
}

void Motocicleta::setCantComb(int c)
{
    cantComb=c;
}

int Motocicleta::getCantComb()
{
    return cantComb;
}

//sets heredados
void Motocicleta::setcantidadPasajeros(int c)
{
    vr->setcantidadPasajeros(c);
}

void Motocicleta::setKMRecorridos(int c)
{
    vr->setKMRecorridos(c);
}

void Motocicleta::setEjes(int j)
{
    vr->setEjes(j);
}

void Motocicleta::setPesoVehiculo(int p)
{
    vr->setPesoVehiculo(p);
}

void Motocicleta::setVelocidadMaxima(int j)
{
    vr->setVelocidadMaxima(j);
}

//Gets heredados
int Motocicleta::getcantidadPasajeros()
{
    return vr->getcantidadPasajeros();
}

int Motocicleta::getKMRecorridos()
{
    return vr->getKMRecorridos();
}

int Motocicleta::getEjes()
{
    return vr->getEjes();
}

int Motocicleta::getPesoVehiculo()
{
    return vr->getPesoVehiculo();
}

int Motocicleta::getVelocidadMaxima()
{
    return vr->getVelocidadMaxima();
}

//Colores
void Motocicleta::setColor(int c)
{
    vr->setColor(c);
}

string Motocicleta::getColor()
{
    return vr->getColor();
}

Motocicleta::~Motocicleta()
{
    //dtor
}
