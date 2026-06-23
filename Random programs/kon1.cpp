#include <iostream>
#include <cmath>
// 1. Напишете функция, която приема символен низ и връща сумата на всички числа в него.

// Вход	Изход
// ab37c10x	47

bool isNumber(char ch)
{
    if (ch >= '0' && ch <= '9')
        return true;
    return false;
}
unsigned charToInt(char ch)
{
    return ch - '0';
}
unsigned sumOfNumbs(char *str)
{
    char *ptr = str;
    unsigned sum = 0;
    unsigned numOfConsecutive = 0;
    unsigned current = 0;
    while (*ptr)
    {
        if (isNumber(*ptr) == true)
        {
            current = 0;
            while (*ptr && isNumber(*ptr) == true)
            {
                current = current * 10 + charToInt(*ptr);
                ptr++;
            }
            sum = sum + current;
        }

        else
            ptr++;
    }

    return sum;
}

int main()
{
    char str[8];
    std::cin >> str;
    std::cout << "Sum of numbs = " << sumOfNumbs(str) << std::endl;

    return 0;
}