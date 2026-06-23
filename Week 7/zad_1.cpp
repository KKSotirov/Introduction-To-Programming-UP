#include <iostream>
const size_t ARR_SIZE = 500;


    void getArray (int arr[], size_t size) {
        for (size_t i = 0; i < size; i++)
        {
            std::cin >> arr[i];
        }
    }

    bool isEqual (int arr[], size_t size) {
        for (size_t i = 0; i < size; i++)
        {
                if (arr[i]==arr[i+1]) return true;
            }
        return false;
    }

int main () 
{   
    int arr[ARR_SIZE];
    size_t length;
    std::cout << "Please enter length of array." << std::endl;
    std::cin >> length;

    getArray(arr,length);
    std::cout << std::boolalpha << isEqual(arr,length);
}