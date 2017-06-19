#include <iostream>

using namespace std;
enum departamento{
        Cortes,
        Atlantida,
        Colon,
        GraciasaDios,
        Yoro,
        IslasdelaBahia,
        Olancho,
        Elparaiso,
        Valle,
        Choluteca,
        FcoMorazan,
        LaPaz,
        Intibuca,
        Lempira,
        Copan,
        Ocotepeque,
        SantaBarbara,
        Comayagua
        };
int main()
{
    int num1=2;
    unsigned int num2=1999999999;
    __int8 caracter='A';
    unsigned __int8 caracter2='a';
    __int16 numcorto=30000;
    unsigned __int16 numcorto2=60000;
    __int32 numsign= -2147483648;
    unsigned __int32 num4 = 2222222;
    unsigned long numlargo= 18999999999;
    float decimal1= 32.56757;
    double decimal2= 54546.64646;
    long double decimal3= 45454545.46464;

    char letra= 'J';
    signed char letra2='e';
    unsigned char letra3='l';
    wchar_t letra4='h';
    char16_t letra5='o';
    char32_t letra6='a';


    departamento Honduras;
    Honduras=Atlantida;//Ingresamos el departamento para ver su posicion en el enum

    if(Honduras == Cortes || Honduras== Atlantida || Honduras==Colon){
        cout << Honduras << endl;
    }else
    {
        cout << "Este no es un departamento valido" << endl;
    }






    cout << num1 << endl;
    cout << num2 << endl;
    cout << caracter << endl;
    cout << caracter2 << endl;
    cout << numcorto << endl;
    cout << numcorto2 << endl;
    cout << numsign << endl;
    cout << num4 << endl;
    cout << numlargo << endl;
    cout << decimal1 << endl;
    cout << decimal2 << endl;
    cout << decimal3 << endl;
    cout << letra << endl;
    cout << letra2 << endl;
    cout << letra3 << endl;
    cout << letra4 << endl;
    cout << letra5 << endl;
    cout << letra6 << endl;





    return 0;
}
