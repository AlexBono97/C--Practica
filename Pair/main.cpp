#include <utility>
#include "mipair.h"
#include <iostream>
#include <string>


using namespace std;

int main()
{
    cout << "probando utility mipair" << endl;
    pair<int, string > p= make_pair(3, "alo");
    cout << p.first << " " << p.second << endl;



    cout << "Probando clase mi pair" << endl;
    mipair * n = new mipair(2,"hola");
    cout << n->first << " " << n->second << endl;

    return 0;
}
