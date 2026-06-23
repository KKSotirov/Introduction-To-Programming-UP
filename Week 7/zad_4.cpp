#include <iostream>
const size_t ARR_SIZE = 128;

void getArray (int arr[], size_t size) {
        for (size_t i = 0; i < size; i++) {
            std::cin >> arr[i];
        }
    }

bool isZigZag (int arr[], size_t size) {
    bool zigZag = false;
    for (size_t i = 0; i < size-1; i++) {
        if (i%2 == 0 && arr[i] < arr[i+1]) zigZag = true;
        else if (i%2 == 0 && arr[i] >= arr[i+1]) return false;
        if (i%2 == 1 && arr[i] > arr[i+1]) zigZag = true;
        else if (i%2 == 1 && arr[i] <= arr[i+1]) return false;
    }
    return zigZag;
}

int main () 
{
    int arr[ARR_SIZE];
    size_t length;
    std::cout << "Enter length of array. " << std::endl;
    std::cin >> length;
    getArray(arr,length);
    std::cout << std::boolalpha << isZigZag(arr,length) << std::endl;

    return 0;
}