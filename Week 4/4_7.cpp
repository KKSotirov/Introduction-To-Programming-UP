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

int main() 
{
    unsigned number1, number2;
    std::cout << "Please enter a integer value for the first number " << std::endl;
    std::cin >> number1;
    std::cout << "Please enter a integer value for the second number " << std::endl;
    std::cin >> number2; 

    unsigned bigger = getBigger(number1, number2);
    unsigned smaller = getSmaller(number1,number2);
    for (size_t i = bigger/2; i > 0; i--) {
            if (bigger%i == 0 && smaller%i == 0) std::cout << i << " ";
    }
    return 0;
}