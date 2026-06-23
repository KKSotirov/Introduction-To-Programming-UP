#include <iostream>
#include <cmath>

    // int getSize (int number) {
    //     int size = 0;
    //     for (; number > 0 ;) {
    //         size++;
    //         number = number/10;
    //     }
    //     return size;
    // }

    int toBinary (int number) {
        int binaryNumber = 0;
        for (int i = 0; i < number; i++) {
            binaryNumber = binaryNumber + (number%2)*pow(10,i);
            number = number/2;
            if (number == 0) return binaryNumber;
        }   
        return binaryNumber;
        }   

int main ()
{
    unsigned number;
    std::cin >> number;
    std::cout << toBinary(number) << std::endl;








    return 0;
}