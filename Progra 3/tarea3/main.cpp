#include <iostream>
#include "nod.h"
using namespace std;

int main()
{
    nod *n= new nod(5);
    n->add(new nod(3));
    (n->sig)->add(new nod(2));
    cout << n->getVal() << endl;
    cout << n->getValSigs() << endl;
    return 0;
}
