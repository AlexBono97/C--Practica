#include <iostream>

using namespace std;

int sumarnumeros(int x, int y)
{
    return x+y;
}

int main()
{
    int a;
    int b;
    std::cout << "Ingrese 2 numeros" << std::endl;
    std::cin >> a;
    std::cin >> b;
    std::cout << "La suma da: " << sumarnumeros(a,b) << std::endl;
    return 0;

}
