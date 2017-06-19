#include <iostream>
#include "rastra.h"
#include "motocicleta.h"
#include "bicicleta.h"
using namespace std;

void imprimirCosto(VehiculoRodante * vr)
{
    cout << "El costo es: " << endl;
    cout << vr->getKMRecorridos() << endl;
}


int main()
{
    Rastra * mirastra = new Rastra(5,80,1500, 15, 1);
    Motocicleta * mimoto = new Motocicleta(2, 40, 800, 10, 8);
    Bicicleta * mibici = new Bicicleta(1,10,4);
    imprimirCosto(mirastra);

    return 0;
}
