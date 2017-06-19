#include <iostream>
#include <string.h>
using namespace std;

struct cliente
{
    char nombre_cliente[25];
    char direccion[25];
    char ciudad[20];
    char provincia[20];
    long int codigo_postal;
    double saldo;
};

void asignarNombre(const char * nombre, cliente * c)
{
    strcpy(c->nombre_cliente, nombre);
}

void asignarDireccion(const char * direccion, cliente * c)
{
    strcpy(c->direccion, direccion);
}

void asignarCiudad(const char * ciudad, cliente * c)
{
    strcpy(c->ciudad, ciudad);
}

void asignarProvincia(const char * provincia, cliente * c)
{
    strcpy(c->provincia, provincia);
}

void asignarPostal(long int codigo, cliente * c)
{
    c->codigo_postal=codigo;
}

void asignarSaldo(double saldo, cliente * c)
{
    c->saldo=saldo;
}

int main()
{
    cliente micliente;

    char nombre[25];
    char direccion[25];
    char ciudad[20];
    char provincia[20];
    long int postal;
    double saldo;

    cout<<"Ingrese un nombre: "<<endl;
    cin>>nombre;
    cout<<"Ingrese una direccion: "<<endl;
    cin>>direccion;
    cout<<"Ingrese una ciudad: "<<endl;
    cin>>ciudad;
    cout<<"Ingrese una provincia: "<<endl;
    cin>>provincia;
    cout<<"Ingrese un codigo postal: "<<endl;
    cin>>postal;
    cout<<"Ingrese un saldo: "<<endl;
    cin>>saldo;


    asignarNombre(nombre, & micliente);
    asignarDireccion(direccion, & micliente);
    asignarCiudad(ciudad, & micliente);
    asignarProvincia(provincia, & micliente);
    asignarPostal(postal, & micliente);
    asignarSaldo(saldo, & micliente);

    cout << "Los datos ingresados son los siguientes: "<< endl;
    cout << "Nombre: "<<micliente.nombre_cliente << endl;
    cout << "Direccion: "<<micliente.direccion << endl;
    cout << "Ciudad: "<<micliente.ciudad << endl;
    cout << "Provincia: "<<micliente.provincia<< endl;
    cout << "Codigo Postal: "<<micliente.codigo_postal << endl;
    cout << "Saldo: "<<micliente.saldo << endl;
    return 0;
}
