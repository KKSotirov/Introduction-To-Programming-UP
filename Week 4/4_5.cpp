#include <iostream>

int main() {
    unsigned number;
    std::cout << "Please enter number." << std::endl;
    std::cin >> number;
    for (size_t i = 0; i < number; i++) {
        for (size_t j = 0; j < number; j++) {
            if (i==j) std::cout << "0";
            else if(i<j) std::cout << "+";
            else if(i>j) std::cout << "-";
        }
        std::cout<<std::endl;
    }

    return 0;
}