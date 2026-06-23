#include <iostream>
const size_t MAX_ARR_SIZE = 1000;

size_t countDigs(size_t num)
{
    int size = 0;
    do
    {
        size++;
        num = num / 10;
    } while (num != 0);
    return size;
}

void initString(char *str)
{
    char ch;
    size_t counter = 0;
    while (counter < MAX_ARR_SIZE - 1 && std::cin.get(ch) && ch != '\n')
    {
        str[counter] = ch;
        counter++;
    }
    str[counter] = '\0';
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

void compressStr(char *str)
{
    int size = 0;

    for (size_t i = 0; str[i] != '\0';)
    {
        int count = 0;
        char ch = str[i];

        while (ch == str[i])
        {
            count++;
            i++;
        }

        size = size + 1;                // 1 mqsto vinagi za bukvata
        size = size + countDigs(count); // + oshte mesta za cifrite zalepeni do bukvite
    }
    // veche imame size, toest znaem kolko pamet shte trqbva da zadelim za noviq "kompresiran" str
    char *compressedStr = new char[size + 1];

    for (size_t i = 0; str[i] != '\0';)
    {
        int count = 0;
        char ch = str[i];

        while (str[i] != '\0' && ch == str[i])
        {
            count++;
            i++;
        }
        *compressedStr = ch;
        compressedStr++;
        *compressedStr = count + '0';
        compressedStr++;
    }
    *compressedStr = '\0';

    std::cout << "The compressed string is: " << std::endl;
    for (size_t i = 0; i < size; i++)
    {
        std::cout << compressedStr[i];
    }
}

int main()
{
    char *str = new char[MAX_ARR_SIZE];
    std::cout << "Please enter sequence of symbols: " << std::endl;
    initString(str);

    compressStr(str);

    delete[] str;
    return 0;
}