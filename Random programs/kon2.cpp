#include <iostream>
const unsigned ALL_CHAR = 255;
// 2. Напишете функция, която приема символен низ и връща нов низ, за който е заделено точно количество памет, който съдържа всички символи от подадения низ, които се срещат само веднъж в него.
// Вход	Изход
// akalhk3g#5ggkkks	lh3#5s

void fillOccurances(char *str, unsigned *allChars)
{
    // obhozhdame go i zapisvme vseki edin element na suotvetnata si poziciq v array allChars[ALL_CHAR]
    // char allChars[ALL_CHAR + 1] = {0};
    char *ptr = str;

    while (*ptr)
    {
        allChars[*ptr]++;
        ptr++;
        // x -> 120 -> allChars[120]++; -> ptr++
    }
}

size_t getSize(char *str)
{
    unsigned size = 0;
    unsigned allChars[ALL_CHAR + 1] = {0};
    fillOccurances(str, allChars);

    for (size_t i = 0; i <= ALL_CHAR; i++)
    {
        if (allChars[i] == 1)
            size++;
    }

    return size;
    // count unique occurances --> size for uniqueStr
}

char *constructUnique(char *str)
{
    unsigned size = getSize(str);
    char *uniqueStr = new char[size + 1];

    unsigned allChars[ALL_CHAR + 1] = {0};
    fillOccurances(str, allChars);

    unsigned currIndex = 0;
    char *ptr = str;
    while (*ptr)
    {
        if (allChars[*ptr] == 1)
        {
            uniqueStr[currIndex] = *ptr;
            currIndex++;
        }
        ptr++;
    }
    uniqueStr[currIndex] = '\0';
    return uniqueStr;
    // sled kato imame size ---> construct --> if (unique) -> fill
}

int main()
{
    char word[100];
    std::cin >> word;

    char *uniqueStr = constructUnique(word);

    while (*uniqueStr)
    {
        std::cout << *uniqueStr << " , ";
        uniqueStr++;
    }

    delete[] uniqueStr;
    return 0;
}