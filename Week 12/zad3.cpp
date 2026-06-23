#include <iostream>

size_t calcExponentiation(size_t number, size_t pow)
{
    if (pow == 1)
        return number;
    else
        return number * calcExponentiation(number, pow - 1);
}

int main()
{
    size_t number, pow;
    std::cout << "Please enter number" << std::endl;
    std::cin >> number;
    std::cout << "Please enter pow" << std::endl;
    std::cin >> pow;
    std::cout << number << "to the power of " << pow << " is = " << calcExponentiation(number, pow);

    return 0;
}