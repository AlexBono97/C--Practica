#include <iostream>
#include <algorithm>
#include <vector>



using namespace std;

//Escriba un programa que desplace a la derecha una variable entera por 4 bits.
//El programa debe imprimir el entero en bits antes y despu�s de la operaci�n de desplazamiento. �Su sistema coloca ceros o unos en los bits vac�os?

unsigned int moverbits(unsigned int num)
{
    unsigned int numero = num;
    unsigned int numero2 = num >>1;//cambiar a 4
    return numero2;

}

unsigned int invertirBits(unsigned int num2)
{
    int numero = num2;
     vector<int> bin, binInv;

     do
     {
          bin.push_back(numero & 1);
          binInv.push_back(~(numero & 1) + 2); //<-- aqu�
          numero >>= 1;
     } while(numero);

     reverse(bin.begin(), bin.end());
     reverse(binInv.begin(), binInv.end());

     cout << "Binario: ";
     for(vector<int>::iterator it = bin.begin(); it != bin.end(); it++)
          cout << *it;

     cout << endl << "Binario Invertido: ";
          for(vector<int>::iterator it = binInv.begin(); it != binInv.end(); it++)
          cout << *it;

     cout << endl;
}

int main()
{
    cout << invertirBits(89)<< endl;



   cout << moverbits(2)<< endl;


    cout << "Hello world!" << endl;
    return 0;
}
