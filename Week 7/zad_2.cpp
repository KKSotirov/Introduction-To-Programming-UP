#include <iostream>
const size_t ARR_SIZE = 30;

void getArray (char arr[], size_t size) {
        for (size_t i = 0; i < size; i++) {
            std::cin >> arr[i];
        }
    }

    bool isBalanced (char arr[], size_t size) {
    int  countBalance = 0;
    for (size_t i = 0; i < size; i++) {
            if (arr[i] == '(') countBalance++;
            else if (arr[i] == ')') countBalance--;
            if (countBalance < 0) return false; 
        }
        return true;
}

int main () 
{
    char arr[ARR_SIZE];
    size_t length;
    std::cout << "Please enter length of array." << std::endl;
    std::cin >> length;
    getArray(arr,length);
    std::cout << std::boolalpha << isBalanced(arr, length) << std::endl;

    return 0;
}