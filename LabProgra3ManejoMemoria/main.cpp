#include <iostream>

using namespace std;

int main()
{
    int num = 10;
    int *apuntador = &num;
    *apuntador = 20;

    cout<<num<<endl;
    cout<<&num<<endl;

    cout<<apuntador<<endl;
    cout<<&apuntador<<endl;
    cout<<*apuntador<<endl;
}
