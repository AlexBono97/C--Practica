#include <iostream>
#include "nodo.h"
#include <vector>
#include <array>

using namespace std;

nodo *m = new nodo();

//Version Recursiva
int potenciaR(int base, int pot, int c)//i por default es 0
{
    if(c<pot)
    {
        return base * potenciaR(base,pot,++c);
    }
    return 1;
}

//Version intermedia
int potenciaI(int resultado, int base)
{
    return resultado * base;
}

//Version con ciclos
int potencia (int base, int e)
{
    int resultado=1;
    for(int i=0; i<e;i++)
    {
      resultado=resultado * base;
    }
    return resultado;
}

//Version con ciclos
int sumaNum(int num)
{
    int resultado=0;
    for(int i=0;i<=num;i++)
    {
        resultado=resultado+i;
    }
    return resultado;

}

//Version Intermedia
int sumaNumi(int resultado, int numero)
{
    return resultado+numero;
}

//Version Recursiva
int sumaNumR(int n)
{
    if(n>1)
    {
        return n+sumaNumR(n-1);
    }
    return 1;
}

//Version Recursiva
int sucesion(int inicio, int buscar, int incre, int c, int n)
{//c=0,n=inicio
    if(buscar>0)
    {
        if(inicio==n)
        {
            cout << "*" << inicio << endl;
            n = inicio + c + 1;
            c=c+incre;
            buscar=buscar-1;
        }
        else
        {
            cout << inicio << endl;
        }
            sucesion(inicio +1,buscar,incre,c,n);
    }

}

//Version Recursiva
void ordenar(nodo * n)//terminar
{
    m->ordenar(n);
}

nodo * menorNodo(nodo * n)//terminar
{


}

void toBin(int num)//terminado
{
    if(num!=0)
    {
        toBin(num/2);
        cout<<num%2;
    }

}


void reverse(string s)//terminado
{
    if(s!="")
    {
        int x= s.length();
        char c = s[x-1];
        s.resize(x-1);
        cout << c ;
        reverse(s);

    }

}



bool isParR(int n, bool par)//ya funciona
{
    if(n==0)
    {
        return par;
    }
    else
    {
        return isParR(n-1,!par);
    }
}
bool isPar(int n)//ya funciona
{
    if(n==0)
    {
        return true;
    }
    else
    {
        return isParR(n-1, false);
    }
}

bool isMR(int n, int  mult)//ya terminada
{
    if(n<0)
    {
        return false;
    }
    if(mult%n==0)
    {
        return true;
    }
    else if(n>0)
    {
        return isMR(n-mult, mult);
    }
    return false;
}


void sucesion1(int inicio, int ini2, int cant, int inc, int cont){//ya terminada
//inin2=inicio,
    int c=0;

    if (cont>=cant)
        return;

    for (c; c<inc; c++){
        if (cont<cant){
            cont++;
            cout<<inicio;
        }
    }

    if (inicio==ini2){
        inicio= inicio+1;
        c=1;
    }

    sucesion1(inicio* c, ini2, cant, inc+1, cont);
}

int Akm(int m, int n)//ya terminada
{
    if(m==0)
    {
        return n+1;
    }
    else if(m>0 && n==0)
    {
        Akm(m-1,1);
    }
    else if(m>0 && n > 0)
    {
        Akm(m-1, Akm(m,n-1));
    }

}

int main()
{
    //ucesion1(0,0,10,2,2);
   // toBin(21);
    //reverse("Hola");
  //cout << Akm(0,2);
 // cout << isMR(8,20);
   // Suc1(10,20,3);

    while(true)
    {
        int option;
        cout<<endl;
        cout<<endl;
        cout<< "Escoja una opcion: "<<endl;
        cout<<"1)Potencia" << endl;
        cout<<"2)Suma Num Sucesivos " << endl;
        cout<<"3)Sucesion" << endl;
        cout<<"4)Ordenar Nodos " << endl;
        cout<<"5)Convertir a Binario " << endl;
        cout<<"6)Imprimir una palabra al reves " << endl;
        cout<<"7)Determinar si es par" << endl;
        cout<<"8)Determinar si es multiplo" << endl;
        cout<<"9)Sucesion2" << endl;
        cout<<"10)Akm" << endl;
        cout<<"11)Salir" << endl;
        cin>>option;

        switch(option)
        {

            case 1:
                {
                int base, exp;
                cout<< "Ingrese un numero base: " ;
                cin>>base;
                cout<< "Ingrese una potencia: " ;
                cin>>exp;
                cout << "Resultado: " <<  potenciaR(base,exp,0)<<endl;
                break;

                }
            case 2:
                {
                int n;
                cout<<"Ingrese un numero: ";
                cin>>n;
                cout<< "Resultado: " << sumaNumR(n)<<endl;
                break;
                }
            case 3:
                {
                    int inicio,cant, incremento, c,n;
                    cout<< "Ingrese un numero inicial: ";
                    cin>>inicio;
                    cout<< "Ingrese la cantidad que desea: ";
                    cin>> cant;
                    cout<<"Ingrese el incremento: " ;
                    cin>>incremento;
                    cout<<"Ingrese C: " ;
                    cin>>c;
                    cout<<"Ingrese N: " ;
                    cin>>n;
                    sucesion(inicio,cant,incremento,c,n);
                    break;
                }
            case 4:
                {
                    cout << "Funcion no implementada"<<endl ;
                    break;
                }
            case 5:
                {
                    int n;
                    cout << "Ingrese el numero: ";
                    cin>>n;
                    toBin(n);
                    break;
                }
            case 6:
                {
                    string s;
                    cout << "Ingrese la palabra: ";
                    cin>>s;
                    reverse(s);
                    break;
                }
            case 7:
                {
                    int n;
                    cout << "Ingrese el numero: ";
                    cin>>n;
                    cout << isPar(n);
                    break;
                }
            case 8:
                {
                    int n, mult;
                    cout<< "Ingrese su numero: ";
                    cin>>n;
                    cout << "Ingrese el multiplo: ";
                    cin>>mult;
                    cout<<isMR(n,mult);
                    break;
                }
            case 9:
                {
                    int inicio, cant, incre, cont;
                    cont=0;
                    cout << "Ingrese su numero de inicio: ";
                    cin>>inicio;
                    cout<< "Ingrese la cantidad: ";
                    cin>>cant;
                    cout<<"Ingrese el incremento ";
                    cin>>incre;
                    sucesion1(inicio,inicio, cant, incre, cont);
                    break;

                }
            case 10:
                {
                    int m,n;
                    cout<<"Ingrese un numero M: ";
                    cin>>m;
                    cout<<"Ingrese un numero N: ";
                    cin>>n;
                    cout << Akm(m,n);
                }
            case 11:
                {
                return 0;
                }

        }



    }
     return 0;
    }
