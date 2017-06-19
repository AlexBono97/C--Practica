#ifndef MIPAIR_H
#define MIPAIR_H
#include <string>

using namespace std;

class mipair
{
    public:
        mipair();
        mipair(int n, string s);
        virtual ~mipair();

        int first;
        string second;

    protected:

    private:
};

#endif // MIPAIR_H
