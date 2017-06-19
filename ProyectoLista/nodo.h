#ifndef NODO_H
#define NODO_H


class Nodo
{
public:
    Nodo(int val);
    int getVal();
    void agregarSig(Nodo *n);
    void agregarAnt(Nodo *n);
    Nodo* getSig();
    Nodo* getAnt();
private:
    int valor;
    Nodo* sig;
    Nodo* ant;
};

#endif // NODO_H
