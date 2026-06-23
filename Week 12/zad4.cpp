#include <iostream>

void initStr(int *str, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        std::cin >> str[i];
    }
}

int sumArray(int *str, size_t size)
{
    if (size == 0)
        return 0;
    else
        return str[size - 1] + sumArray(str, size - 1);
}

int main()
{
    size_t size;
    std::cout << "Please enter size of array so I do not have to alloc memory for no reason..." << std::endl;
    std::cin >> size;
    int *str = new int[size];
    initStr(str, size);
    std::cout << "The sum of the array is = " << sumArray(str, size) << std::endl;

    delete[] str;
    return 0;
}