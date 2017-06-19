#include <iostream>

using namespace std;

int main()
{
   double notas[3];

   for(int i=0;i<3;i++)
   {
       cout<<"Ingrese una nota: ";
       cin>>notas[i];
   }

   double suma = 0;
   cout<<"Las notas ingresadas son: "<<endl;
   for(int i=0;i<3;i++)
   {
       suma+=notas[i];
       cout<<notas[i]<<",";
   }

   cout<<endl;
   cout<<"El promedio es: "<<(suma/3)<<endl;

   return 0;
}
