#include <iostream>
#include "agenda.h"
#include "contacto.h"
#include "ultimallamada.h"

using namespace std;

int main()
{
    agenda * manage = new agenda();
    ultimallamada * manage2 = new ultimallamada();

    contacto * contacto1 = new contacto("Juan", 9845, 0);
    contacto * contacto2 = new contacto("Jose", 9846, 0);
    contacto * contacto3 = new contacto("Josue", 9847, 0);
    contacto * contacto4 = new contacto("Jessica", 9848, 0);
    contacto * contacto5 = new contacto("Jaime", 9999, 0);

   // ultimallamada * registro1 = new ultimallamada(contacto1,0);
   // manage2->add(registro1);


    manage->add(contacto1);
    manage->add(contacto2);
    manage->add(contacto3);
    manage->add(contacto4);
    manage->add(contacto5);


    // manage->llamar(1);
    cout << manage->buscar(9999).second<<endl;
    cout << manage->getContacto(manage->buscar(9999).second)->nombre << endl;

    manage->imprimirAgenda();

    cout << "Hello world!" << endl;
    return 0;
}
