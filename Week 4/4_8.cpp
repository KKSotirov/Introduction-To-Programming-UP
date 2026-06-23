#include <iostream>
#include<algorithm>

    unsigned getSize (unsigned number) {
        unsigned size = 0;
        for (;number != 0;) {
            number = number/10;
            size++;
        }
        return size;
    }
    void getMostFrequentNumber  (unsigned number) {
        unsigned countOfMostFrequentNumber = 0, mostFrequentNumber, size, copyOfNumber, countOfCurrentNumber;
        size = getSize(number);

        for (size_t i = 0; i < size; i++) {
            copyOfNumber = number;
            
            for (size_t j = 0; j < 10; j++) {
            if (copyOfNumber % 10 == j) {
                countOfCurrentNumber++;
                copyOfNumber/=10;
            }
            
            if (countOfCurrentNumber > countOfMostFrequentNumber) {
                mostFrequentNumber = j;
                countOfMostFrequentNumber = countOfCurrentNumber;
            }
        }
    }
             //std::cout << std::max({countOfZeros, countOfOnes, countOfTwos, countOfThrees, countOfFours, countOfFives, countOfSixes, countOfSevens, countOfEights, countOfNines});
    }

int main () 
{
    unsigned number;
    std::cout << "Please enter number." << std::endl;
    std::cin >> number;
//    std::cout << "size of number is: " << getSize(number) << std::endl;    
    getMostFrequentNumber(number);
    
    return 0;
}