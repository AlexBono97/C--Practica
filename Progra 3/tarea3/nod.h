#ifndef NOD_H
#define NOD_H


class nod
{
    public:
        nod(int v);
        int getVal();
        int getValSigs();
        virtual ~nod();
        nod* sig;
        void add(nod* n);
    protected:

    private:
        int valor;
};

#endif // NOD_H
