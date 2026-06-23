#include <iostream>
size_t factoriel(size_t number)
{
    if (number == 1)
        return 1;
    else
        return number * factoriel(number - 1);
}

int main()
{
    size_t number;
    std::cin >> number;
    std::cout << number << "! is equal to: " << factoriel(number);
    return 0;
}