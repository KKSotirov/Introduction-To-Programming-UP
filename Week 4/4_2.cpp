#include <iostream> 

    int getSize (int number) {
        int length = 0;
        for (; number != 0; ) {
            number = number/10;
            length++;
        }
         return length;
    }

int main () 
{
    int number, desiredIndex;
    std::cout << "Please enter a number." << std::endl;
    std::cin >> number;
    std::cout << "Please enter desired index." << std::endl;
    std::cin >> desiredIndex;
    if (getSize(number) > desiredIndex) {
    int count = getSize(number) - desiredIndex;

    for (size_t i = 0; i < count; i++ ) {
        number = number/10;
        }
    unsigned numAtDesiredIndex = number % 10;
    std::cout << "The number at index " << desiredIndex << " is: " << numAtDesiredIndex << std::endl;
    } else std::cout << "There is no digit on index " << desiredIndex << std::endl;

    return 0;
}