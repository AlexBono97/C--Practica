#include "vehiculorodante.h"

VehiculoRodante::VehiculoRodante()
{

}

VehiculoRodante::~VehiculoRodante()
{
    //dtor
}

VehiculoRodante::VehiculoRodante(int cp, int kmr, int col)
{
    setColor(col);
    KMrecorridos=kmr;
    cantidadPasajeros=cp;
}

//sets y gets
void VehiculoRodante::setcantidadPasajeros(int cp)
{
    cantidadPasajeros=cp;
}

void VehiculoRodante::setKMRecorridos(int kmr)
{
    KMrecorridos=kmr;
}

void VehiculoRodante::setEjes(int eje)
{
    ejes=eje;
}

void VehiculoRodante::setPesoVehiculo(int peso)
{
    pesoVehiculo=peso;
}

void VehiculoRodante::setVelocidadMaxima(int v)
{
    VelocidadMaxima=v;
}

int VehiculoRodante::getcantidadPasajeros()
{
    return cantidadPasajeros;
}

int VehiculoRodante::getKMRecorridos()
{
    return KMrecorridos;
}

int VehiculoRodante::getEjes()
{
    return ejes;
}

int VehiculoRodante::getPesoVehiculo()
{
    return pesoVehiculo;
}

int VehiculoRodante::getVelocidadMaxima()
{
    return VelocidadMaxima;
}

void VehiculoRodante::setColor(int c)
{
    switch(c)
    {
    case 0:
        color2="Azul";
        break;
    case 1:
        color2="Amarillo";
        break;
    case 3:
        color2="Verde";
        break;
    case 4:
        color2="Negro";
        break;
    case 5:
        color2="Gris";
        break;
    case 6:
        color2="Blanco";
        break;
    case 7:
        color2="Rojo";
        break;
    case 8:
        color2="Plateado";
        break;
    case 9:
        color2="Cafe";
        break;
    }

}

string VehiculoRodante::getColor()
{
    return color2;
}


