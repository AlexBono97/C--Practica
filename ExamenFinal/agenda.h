#ifndef AGENDA_H
#define AGENDA_H
#include <iostream>
#include <string>
#include "contacto.h"
#include "ultimallamada.h"

using namespace std;


class agenda
{
    public:
        agenda();

        //atributos
        contacto * contactoHead;
        ultimallamada * ultimallamadaHead;
        int CantContactos;

        //prueba
        void setUltimaHead(ultimallamada * c);
        ultimallamada * getUltimaHead();

        //funciones y metodos
        bool seRepite(int n);
        void add(contacto * c);
        std::pair<bool,int> buscar(int numecontacto);//validamos de que existe
        contacto * getContacto(int pos);
        void llamar(int pos);
        void imprimirAgenda();
        void imprimirUltimasLlamadas();


        virtual ~agenda();

    protected:

    private:
};

#endif // AGENDA_H
