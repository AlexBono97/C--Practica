#include <iostream>
#include "cliente.h"
#include "empleado.h"

using namespace std;

int main()
{


    //Trabajando con cliente
    cliente * c = new cliente();
    c->setNombre_cliente("Juan Alberto");
    cout << "Nombre: "<< c->getNombre_cliente() << endl;

    c->setSaldo(9888);
    cout << "Saldo: " << c->getSaldo() << endl;

    c->setDireccion_cliente("Los Alamos");
    cout << "Direccion: " << c->getDireccion_cliente()<<endl;

    c->setCiudad_cliente("Choloma");
    cout << "Ciudad: " << c->getCiudad_cliente() << endl;

    c->setProvincia_cliente("Cortes");
    cout << "Provincia: " << c->getProvincia_cliente()<<endl;

    c->setCdPostal_cliente(70065);
    cout << "Codigo Postal: "<< c->getCdPostal_cliente()<<endl;

    //Trabajando con empleado
    Empleado * k = new Empleado();

    cout << endl;
    k->setNombre_empleado("Jose");
    cout << "Nombre de Empleado: " << k->getNombre_empleado() << endl;

    k->setDireccion_empleado("Kennedy");
    cout << "Direccion: "<< k->getDireccion_empleado()<<endl;

    k->setCiudad_empleado("Tegucigalpa");
    cout << "Ciudad: "<< k->getCiudad_empleado()<<endl;

    k->setProvincia_empleado("Fco Morazan");
    cout << "Provincia: "<< k->getProvincia_empleado()<<endl;

    k->setCdPostal_empleado(70063);
    cout << "Codigo Postal: " << k->getCdPostal_empleado()<<endl;

    k->setSalario(6700);
    cout << "Salario: " << k->getSalario()<<endl;


    return 0;
}
