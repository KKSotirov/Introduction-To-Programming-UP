#include <iostream>
#include <cmath>

    int getSize (int number) {
        int size = 0;
        for (; number > 0 ;) {
            size++;
            number = number/10;
        }
        return size;
    }


    int getLastDigits (int number1, int count) {
        int desiredDigits = 0;
        for (size_t i = 0; i < count; i++) {
        desiredDigits = (number1%10) * pow(10,i) + desiredDigits;
        number1 = number1/10;
        }
        return desiredDigits;
    }

    int addDigits (int number2, int digits) {
    return (digits*pow(10,getSize(number2))) + number2;    
    }

int main() 
{
    int number1, number2, countOfDigits;
    std::cout << "Please enter values:" << std::endl;
    std::cin >> number1 >> number2 >> countOfDigits;

    std::cout << "Desired digits are: " << getLastDigits(number1, countOfDigits) << std::endl;
    std::cout << "Size of number2 is: " << getSize(number2) << std::endl;
    std::cout << "Newly formed number: " << addDigits (number2, getLastDigits(number1, countOfDigits)) << std::endl;


    return 0;
}