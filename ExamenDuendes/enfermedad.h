#ifndef ENFERMEDAD_H
#define ENFERMEDAD_H
#include "duende.h"


class enfermedad
{
    public:
        enfermedad();
        virtual ~enfermedad();
        void virtual afectar(duende * p);

    protected:

    private:
};

#endif // ENFERMEDAD_H
