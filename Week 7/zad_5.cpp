#include <iostream>
const size_t ARR_SIZE = 64;

int getArray (int arr[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        std::cin >> arr[i];
    }
}

int sumOfUnique (int arr[], size_t size) {
    bool isUnique = true;
    int sum = 0;
    int arrCopy[ARR_SIZE];
    for (size_t i = 0; i < size; i++) {
        if (i == 0) {
        sum = sum + arr[i];
        arrCopy[i] = arr[i];
        }
        else for (size_t j = 0; j < i; j++) {
            if (arr[i] == arrCopy[j]) {
                isUnique = false;
                sum = sum - arr[i];
                break;
            } 
            else isUnique = true;
        }

        if (isUnique == true) {
        sum = sum + arr[i];
        arrCopy[i] = arr[i];
        isUnique = false;
        }
        if (sum < 0) sum = 0;
    }
    return sum;
}



int main () 
{
    size_t length;
    int arr[ARR_SIZE];
    std::cout << "Please enter length of array." << std::endl;
    std::cin >> length;
    getArray(arr,length);
    
    std::cout << "Sum of all unique numbers is: " << sumOfUnique(arr,length) << std::endl;




    return 0;
}