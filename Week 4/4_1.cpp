#include <iostream>

int main () {
    unsigned number;
    bool IsPrime = true;
    std::cout << "Please enter a positive integer." << std::endl;
    std::cin >> number;

    for (int i = 2; i < (number/2); i++) {
        if (number % i == 0) IsPrime = false;
    }
    if (IsPrime = true ) {
        std::cout << "The entered number is prime" << std::endl;
    }
        else std::cout << "The entered number is not prime" << std::endl;



    return 0;
}