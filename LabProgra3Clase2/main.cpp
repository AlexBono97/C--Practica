#include <iostream>

using namespace std;

int main()
{
   int arreglo[3];
   arreglo[0]=10;
   arreglo[1]=20;
   arreglo[2]=30;

   int *ptr = arreglo;
   ptr[0]=100;

   cout << arreglo[0] <<endl;
   cout << arreglo[1] <<endl;
   cout << arreglo[2] <<endl;
