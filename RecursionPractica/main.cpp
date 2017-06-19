#include <iostream>

using namespace std;

//Tarea 1
int potenciaR(int base, int pot, int i)
{
     if(i<pot)
    {
        return base * potenciaR(base,pot,++i);
    }
    return 1;
}

//Tarea 2
int suma(int num)
{
    if(n>1)
    {
        return n+sumaNumR(n-1);
    }
    return 1;
}



int main()
{
    cout << "Suma" << suma(5) << endl;
    cout << potenciaR(2,3,0)<<endl;
    cout << "Hello world!" << endl;
    return 0;
}
