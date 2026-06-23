#include <iostream>
const size_t MAX_ARR_SIZE = 100;

void initStr(char *str)
{
    char ch;
    while (std::cin.get(ch) && ch != '\n')
    {
        *str = ch;
        str++;
    }
    *str = '\0';
}

int strLen(char *str)
{
    int size = 0;
    while (*str)
    {
        str++;
        size++;
    }
    return size;
}

int countOfOccurances(char *text, char *pattern)
{
    int successive = 0, timesFound = 0;
    for (size_t i = 0; text[i] != '\0'; i++)
    {
        while (text[i] == pattern[successive] && text[i] != '\0' && pattern[successive] != '\0')
        {
            successive++;
            i++;
        }
        if (successive == strLen(pattern))
        {
            timesFound++;
        }
        if (successive != 0)
            i--;
        successive = 0;
    }
    return timesFound;
}

int main()
{
    char *text = new char[MAX_ARR_SIZE];
    char *pattern = new char[MAX_ARR_SIZE];
    std::cout << "Please enter text: " << '\n';
    initStr(text);
    std::cout << "Please enter pattern: " << '\n';
    initStr(pattern);
    std::cout << "Times found = " << countOfOccurances(text, pattern) << std::endl;

    delete[] text;
    delete[] pattern;
    return 0;
}