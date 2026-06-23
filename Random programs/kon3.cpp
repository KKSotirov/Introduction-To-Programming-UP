#include <iostream>
bool isNumber(char ch)
{
}

bool isSQRT(int n)
{
}

int charToInt(char ch)
{
}

int countSQRTS(const char *str)
{
    int count = 0;
    int currentNumber = 0;
    bool inNumber = false;
    const char *ptr = str;
    while (*ptr)
    {
        if (isNumber(*ptr) == true)
        {
            inNumber = true;
            currentNumber = currentNumber * 10 + charToInt(*ptr);
        }
        if (isNumber(*ptr) == false)
        {
            if (inNumber = true)
            {
                if (isSQRT(currentNumber) == true)
                    count++;
                currentNumber = 0;
                inNumber = false;
            }
        }
    }
    // ima vuzmozhnost obache posleden char da e cifra ==> da ne se stigne do proverkata za isSQRT
    if (inNumber = true)
    {
        if (isSQRT(currentNumber) == true)
            count++;
    }
    return count;
}