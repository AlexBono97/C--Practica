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

void asignarCiudad(const char * ciudad,cliente *c)
{
    strcpy(c->ciudad,ciudad);

}

void asignarNombre(const char * nombre, cliente *c)
{
    strcpy(c->nombre_cliente,nombre);
}

void asignarDireccion(const char * direccion,cliente* c)
{
    strcpy(c->direccion,direccion);
}

void asignarProvincia(const char * provincia,cliente* c)
{
    strcpy(c->provincia,provincia);
}

void asignarCodigoPostal(const long int codigo_postal,cliente* c)
{
    c->codigo_postal=codigo_postal;
}

void asignarSaldo(const double saldo,cliente* c)
{
    c->saldo=saldo;
}


int main()
{
    cliente micliente;
    asignarNombre("Lourdes",&micliente);
    asignarDireccion("Barrio los angeles",&micliente);
    asignarCiudad("El Progreso", &micliente);
    asignarProvincia("Yoro", &micliente);
    asignarCodigoPostal(504,&micliente);
    asignarSaldo(2500.36,&micliente);


    cout<<micliente.nombre_cliente<<endl;
    cout<<micliente.direccion<<endl;
    cout<<micliente.ciudad<<endl;
    cout<<micliente.provincia<<endl;
    cout<<micliente.codigo_postal<<endl;
    cout<<micliente.saldo<<endl;

    return 0;
}
