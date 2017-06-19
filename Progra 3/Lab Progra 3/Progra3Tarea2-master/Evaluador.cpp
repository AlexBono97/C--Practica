#include "Evaluador.h"



void evaluar()
{
    float nota = 0;

    cout<<"Ejercicio obtenerValor:\t\t\t";
    if(obtenerValor(new int(5))==5 && obtenerValor(new int(7))==7 && obtenerValor(new int(2))==2)
    {
        nota+=1;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<"Ejercicio sumar:\t\t\t";
    if(sumar(new int(5),new int(5))==10 && sumar(new int(7),new int(5))==12 && sumar(new int(5),new int(2))==7)
    {
        nota+=1;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<"Ejercicio compararApuntadores:\t\t";
    string *x=new string("");
    if(compararApuntadores(new string(""),new string(""))==false && compararApuntadores(new string(""),new string(""))==false && compararApuntadores(x,x)==true)
    {
        nota+=1;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<"Ejercicio comparar:\t\t\t";
    if(comparar(new string("abc"),new string("abc"))==true && comparar(new string("abc"),new string("abd"))==false && comparar(new string("abc"),new string("ab"))==false)
    {
        nota+=1;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<"Ejercicio getPrimeraLetra:\t\t";
    if(getPrimeraLetra(new string("abc"))=='a' && getPrimeraLetra(new string("qwe"))=='q' && getPrimeraLetra(new string("xtr"))=='x')
    {
        nota+=1;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<"Ejercicio esPalindromo:\t\t\t";
    if(esPalindromo(new string("aba"))==true && esPalindromo(new string("qwe"))==false && esPalindromo(new string("abba"))==true && esPalindromo(new string("allia"))==false)
    {
        nota+=1;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<"Ejercicio getExponente:\t\t\t";
    if(getExponente(new int(2),new int(2))==4 && getExponente(new int(2),new int(3))==8 && getExponente(new int(3),new int(2))==9)
    {
        nota+=1;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<endl<<"Nota: "<<nota<<"/7"<<endl;
}
