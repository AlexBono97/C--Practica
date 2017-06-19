#ifndef MIMAPA_H
#define MIMAPA_H
#include "minodo.h"


class mimapa
{
    public:
        mimapa();
        void Add(int key, int valor);
        void Remove(int key);
        int contar();
        bool isEmpty();
        void Reset();
        int getCont(int key);
        void Reordenar(int key);
        void checkKey(int key);

        //Punteros

        virtual ~mimapa();

    protected:

    private:

};

#endif // MIMAPA_H
