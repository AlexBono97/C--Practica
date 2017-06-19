#include <iostream>
#include "Cliente.h"
using namespace std;

int main()
{
    Cliente *c = new Cliente();

    c->setNombre("Lourdes");
    c->setDireccion("B los Angeles");
    c->setCiudad("El Progreso");
    c->setProvincia("Yoro");
    c->setCodigoPostal(504);
    c->setSaldo(5600.36);

    cout<<c->getNombre()<<endl;
    cout<<c->getDirecion()<<endl;
    cout<<c->getCiudad()<<endl;
    cout<<c->getProvincia()<<endl;
    cout<<c->getCodigoPostal()<<endl;
    cout<<c->getSaldo()<<endl;

    cout << "Hello world!" << endl;
    return 0;
}
