#include <iostream>
#include <cmath> 
    unsigned getSize (unsigned number) {
        unsigned size = 0;
        for (;number != 0;) {
            number = number/10;
            size++;
        }
        return size;
    }

    unsigned toDecimal (unsigned binaryNumber) {
        size_t size = getSize(binaryNumber);
        unsigned decimalValue = 0;
        unsigned numAtDesiredIndex;
        for (int i = 0; i < size ; i++) {
            numAtDesiredIndex = binaryNumber % 2;
            binaryNumber = binaryNumber/10;

            if (numAtDesiredIndex == 1) decimalValue = decimalValue + pow(2,i);
        }
        return decimalValue;
    }

int main ()
{
    unsigned binaryNumber;
    std::cout << "Please enter number in binary" << std::endl;
    std::cin >> binaryNumber;
    std::cout << "The binary number: " << binaryNumber << " equals " << toDecimal(binaryNumber) << " in decimal." << std::endl;
    return 0;
} 