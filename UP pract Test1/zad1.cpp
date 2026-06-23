#include <iostream>

void simplify (int number1, int number2) {
    int gcd = 1;
    int min;
    if ((number1 < number2 && number1 != 0)) min = number1;
    else min = number2;
    
    for (int i = min; i > 0; i--) {
        if (number1 % i == 0 && number2 % i == 0) {
            gcd = i;
            break;
        }
    }
    // number1 = number1 / gcd;
    // number2 = number2 / gcd;
    // std::cout << number1 << "/" << number2 << std::endl;
        std::cout << gcd;
}

int main () 
{
    int number1, number2;
    std::cout << "Enter number1." << std::endl;
    std::cin >> number1;
    std::cout << "Enter number2." << std::endl;
    std::cin >> number2;

    simplify(number1,number2);
    return 0;
}