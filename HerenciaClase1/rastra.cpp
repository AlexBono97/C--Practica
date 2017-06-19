#include "rastra.h"
#include "vehiculorodante.h"

Rastra::Rastra()
{
    //ctor
}

Rastra::Rastra(int cp, int kmr, int tm, int cantComb, int col) : VehiculoRodante(cp,kmr,col)
{

    setTamanoMotor(tm);
    setCantComb(cantComb);

}

Rastra::~Rastra()
{
    //dtor
}

void Rastra::setTamanoMotor(int m)
{
    tamanoMotor=m;
}

int Rastra::getTamanoMotor()
{
    return tamanoMotor;
}

double Rastra::getCostoKMRecorridos()
{
    double k=VehiculoRodante::getKMRecorridos();


    double costoKMRecorridos=(k/cantComb)*90;
    return costoKMRecorridos;
}

void Rastra::setCantComb(int c)
{
    cantComb=c;
}

int Rastra::getCantComb()
{
    return cantComb;
}

//sets heredados
void Rastra::setcantidadPasajeros(int c)
{
    vr->setcantidadPasajeros(c);
}

void Rastra::setKMRecorridos(int c)
{
    vr->setKMRecorridos(c);
}

void Rastra::setEjes(int j)
{
    vr->setEjes(j);
}

void Rastra::setPesoVehiculo(int p)
{
    vr->setPesoVehiculo(p);
}

void Rastra::setVelocidadMaxima(int j)
{
    vr->setVelocidadMaxima(j);
}

//Gets heredados
int Rastra::getcantidadPasajeros()
{
    return vr->getcantidadPasajeros();
}

int Rastra::getKMRecorridos()
{
    return vr->getKMRecorridos();
}

int Rastra::getEjes()
{
    return vr->getEjes();
}

int Rastra::getPesoVehiculo()
{
    return vr->getPesoVehiculo();
}

int Rastra::getVelocidadMaxima()
{
    return vr->getVelocidadMaxima();
}

//Colores
void Rastra::setColor(int c)
{
    vr->setColor(c);
}

string Rastra::getColor()
{
    return vr->getColor();
}
