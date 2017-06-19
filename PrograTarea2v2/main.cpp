#include <iostream>

using namespace std;

struct cliente
{
    string nombre_cliente;
    string direccion;
    string ciudad;
    string provincia;
    long int codigo_postal;
    double saldo;
};

void asignarNombre(string nombre, cliente * c)
{
    c->nombre_cliente=nombre;
}

void asignarDireccion(string direccion, cliente * c)
{
    c->direccion=direccion;
}

void asignarCiudad(string ciudad, cliente * c)
{
    c->ciudad=ciudad;
}

void asignarProvincia(string provincia, cliente * c)
{
    c->provincia=provincia;
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

    string nombre;
    string direccion;
    string ciudad;
    string provincia;
    long int postal;
    double saldo;

    cout << "Ingrese un nombre:" << endl;
    cin>>nombre;
    cout << "Ingrese una direccion:" << endl;
    cin >>direccion;
    cout<< "Ingrese una ciudad:" << endl;
    cin>>ciudad;
    cout<< "Ingrese una provincia:" << endl;
    cin>>provincia;
    cout<< "Ingrese un codigo postal:" << endl;
    cin>>postal;
    cout<< "Ingrese un saldo:" << endl;
    cin>>saldo;

    asignarNombre(nombre, & micliente);
    asignarDireccion(direccion, & micliente);
    asignarCiudad(ciudad, & micliente);
    asignarProvincia(provincia, & micliente);
    asignarPostal(postal, & micliente);
    asignarSaldo(saldo, & micliente);

    cout << "Los datos guardados son los siguientes: " << endl;
    cout << "Nombre: " << micliente.nombre_cliente << endl;
    cout << "Direccion: " << micliente.direccion << endl;
    cout << "Ciudad: " << micliente.ciudad << endl;
    cout << "Provincia: " << micliente.provincia<< endl;
    cout << "Codigo postal: " << micliente.codigo_postal << endl;
    cout <<  "Saldo: " << micliente.saldo << endl;

   return 0;
}
