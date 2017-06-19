#ifndef CONTACTO_H
#define CONTACTO_H
#include <string>

using namespace std;

class contacto
{
    public:
        contacto();
        contacto(string n, int num, int oper);
        //atributos
        string nombre;
        int numContacto;
        enum operador{Tigo,Claro,Hondutel};
        int operadorCel;

        //funciones
        contacto * getSig();
        void setSig(contacto * c);
        int getnumero();

        //apuntadores
        contacto * sig;
        virtual ~contacto();

    protected:

    private:
};

#endif // CONTACTO_H
