#include <iostream>
const int MIN_INT = -2147483648;

int main () 
{
    unsigned count;
    int maxNumber = MIN_INT, secondNumber = MIN_INT, currentNumber;
    std::cout << "Please enter value of count " << std::endl;
    std::cin >> count;

    if (count >= 2) {
    for (size_t i = 0; i < count; i++) {
        std::cout << "enter number: " << std::endl;
        std::cin >> currentNumber;
        if (currentNumber > maxNumber ) maxNumber = currentNumber;
        else if (currentNumber > secondNumber) secondNumber = currentNumber;

    }
    std::cout << "The biggest number is: " << maxNumber << ", and the second biggest is: " << secondNumber << std::endl;

}   else std::cout << "Please enter more numbers." << std::endl;
    return 0;
}