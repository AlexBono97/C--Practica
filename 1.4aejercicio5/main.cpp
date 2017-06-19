#include <iostream>

using namespace std;

int doubleNumber(int x)
{
    return x*2;
}

int main()
{
    int y;
    std::cout << "Write a number" << std::endl;
    std::cin >> y;
    std::cout << doubleNumber(y) << std::endl;
    return 0;
}
