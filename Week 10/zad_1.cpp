#include <iostream>
const size_t MAX_ARR_SIZE = 100;

void initArray(char *str, size_t size)
{
    std::cout << "Please enter a string: ";
    for (size_t i = 0; i < size; i++)
    {
        std::cin >> *str;
        str++;
    }
    *str = '\0';
}

void getArray(char *str)
{
    while (*str)
    {
        std::cout << *str;
        str++;
    }
    std::cout << std::endl;
}

size_t strLen(char *str)
{
    size_t len = 0;
    while (*str)
    {
        len++;
        str++;
    }
    return len;
}

void strCopy(char *str)
{
    size_t len = strLen(str);
    char *tmp = new char[len + 1];
    for (size_t i = 0; i < len; i++)
    {
        *tmp = *str;
        tmp++;
        str++;
    }
}

void strConCat(char *str1, char *str2)
{
    char *strConcat = new char[(strLen(str1) + strLen(str2))];
}

int main()
{
    char *str = new char[MAX_ARR_SIZE];
    size_t size = 0;
    std::cout << "Please enter size of string: ";
    std::cin >> size;
    initArray(str, size);
    std::cout << "size of string by function strLen: " << strLen(str) << '\n';

    return 0;
}