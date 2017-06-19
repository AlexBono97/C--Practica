#include <iostream>

int main()
{   //this prints a sentence
    std::cout << "Write a number: ";
    int x;
    //this assigns the input of the user
    std::cin >> x;
    //this prints again
    std::cout << "You wrote " << x << std::endl;
    return 0;
}
