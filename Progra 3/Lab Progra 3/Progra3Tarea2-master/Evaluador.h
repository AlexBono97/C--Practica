#ifndef EVALUADOR_H
#define EVALUADOR_H

#include <iostream>       // std::cin, std::cout
#include <stack>          // std::stack
using namespace std;

void evaluar();

int obtenerValor(int *ptr);
int sumar(int* a, int* b);
bool compararApuntadores(string *a, string *b);
bool comparar(string *a, string *b);
char getPrimeraLetra(string* a);
bool esPalindromo(string* a);
int getExponente(int* base, int* exponente);
#endif // EVALUADOR_H
