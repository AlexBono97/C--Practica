#include "Evaluador.h"
#include <iostream>
using namespace std;

//Desrefencia ptr (dado) y devuelve su valor
int obtenerValor(int *ptr)
{

    int puntero=*ptr;
    return puntero;
}

//Desreferencia a (dado) y b (dado) y devuelve la suma de ambos
int sumar(int* a, int* b)
{
    int puntero1=*a;
    int puntero2=*b;
    return puntero1 + puntero2;
}

//Devuelve true si a (dado) y b (dado) apuntan al mismo espacio de memoria
bool compararApuntadores(string *a, string *b)
{
    if(a==b)
        return true;
    return false;

}

//Desrefencia a (dado) y b (dado), devuelve true si ambos valores son iguales de lo contrario devuelve false
bool comparar(string *a, string *b)
{
    return *a==*b;

}

//Desreferencia a (dado) y devuelve su primera letra
char getPrimeraLetra(string* a)
{
    string g=*a;

    return ' ';
}

//Desreferencia a (dado) y devuelve true si es palindroma de lo contrario devuelve false
//Definicion de palindromo: http://es.wikipedia.org/wiki/Pal%C3%ADndromo
//Ejemplos de palindromos: Ana, arenera, arepera, anilina, ananá, Malayalam, Neuquén, Oruro, oso, radar, reconocer, rotor, salas, seres, somos, sometemos
bool esPalindromo(string* a)
{
    string c = a;
    if (c == string(c.rbegin(), c.rend()))
        return true;
    return false;
}

//Desreferencia base (dado) y exponente (dado) y devuelve la base elevado al exponente
int getExponente(int* base, int* exponente)
{
    return -1;
}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}
