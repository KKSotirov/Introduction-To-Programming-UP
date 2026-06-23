#include <iostream>
unsigned getBigger (unsigned number1, unsigned number2) {
        unsigned bigger;
        if (number1 >= number2) bigger = number1;
        else if (number1 < number2) bigger = number2;
        return bigger;
    }

    unsigned getSmaller (unsigned number1, unsigned number2) {
        unsigned smaller;
        if (number1 > number2) smaller = number2;
        else if (number1 <= number2) smaller = number1;
        return smaller;
    }

int main () 
{
    unsigned number1, number2;
    //euclid's algorithm
    std::cout << "Please enter the first number." << std::endl;
    std::cin >> number1;
     std::cout << "Please enter the second number." << std::endl;
    std::cin >> number2;
    unsigned bigger = getBigger(number1, number2);
    unsigned smaller = getSmaller(number1, number2);
    unsigned remainder;

    do {
        remainder = bigger % smaller;
        if (remainder == 0) break;
        bigger = smaller;
        smaller = remainder;

    } while (remainder != 0);
    unsigned greatestCommonDivisor = smaller;

    std::cout << "The greatest common divisor is: " << greatestCommonDivisor << std::endl; 



}