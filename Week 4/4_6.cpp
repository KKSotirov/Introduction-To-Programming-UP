#include <iostream>

int main() 
{
    unsigned number;
    std::cout << "Please enter value of integer" << std::endl;
    std::cin >> number;
    
    for (size_t i = 0; i < number; i++) {
        for (size_t j = 0; j < number; j++) {
            if ((i + j) == number) std::cout << "x = " << i << ", y = " << j << std::endl;
        }    
    }
    return 0;
}