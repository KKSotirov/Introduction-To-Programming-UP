#include <iostream>
const size_t ARR_SIZE = 150;

    void getArray (char arr[], size_t size) {
        for (size_t i = 0; i < size; i++) {
            std::cin >> arr[i];
        }
    }
  
    bool isSymbol (char arr[], size_t size, char symbol, size_t currIndex) {
        if (arr[currIndex] == symbol) return true;
        return false;
    }
  
    int countOfOccurance (char arr[], size_t size, char symbol) {
        unsigned count = 0;
        for (size_t i = 0; i < size; i++) if (isSymbol(arr,size,symbol, i) == true) count ++;
        return count;
    }
  
    void occuranceToStar (char arr[], size_t size, char symbol) {
        for (size_t i = 0; i < size; i++) if (isSymbol(arr,size,symbol,i) == true) arr[i] = '*';
    } 
  
    void printArray (char arr[], size_t size) {
        for (size_t i = 0; i < size; i++) std::cout << arr[i];
    }

int main () 
{
    char arr[ARR_SIZE], symbol;
    size_t length;
    std::cout << "Enter length of array. " << std::endl;
    std::cin >> length;
    std::cout << "Enter symbol. " << std::endl;
    std::cin >> symbol;
    getArray(arr,length);
    int countOfOccurances = countOfOccurance(arr,length,symbol);
    occuranceToStar(arr,length,symbol);
    printArray(arr,length);
    std::cout << "Number of instances: " << countOfOccurance << std::endl;

    return 0;
}