#include <iostream>


int main () 
{
    unsigned N;
    std::cout << "Please enter value of N" << std::endl;
    std::cin >> N;

    unsigned singularShiftDown = 3*N;

    if (N >= 2 && N <= 9){
        for (size_t i = 1; i <= 80; i++) {
            for (size_t j = 1; j <= 25; j++) {

        //     if (j == (2*N+1)) {
        //        if (i== ((80 -3*N)/2)) {
        //         std::cout << "1";
        //     }
        // }
                if (i == (80 - 3*N)/2 + 1) {
                        for (size_t k = 0; i <= 2*N; i++)
                        {
                            if (j == (singularShiftDown + i)) std::cout << "1";
                        }
               } 

            }
    }
}
    else std::cout << "Incorrect input" << std::endl;
    return true;
}
