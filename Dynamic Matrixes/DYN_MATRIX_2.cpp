#include <iostream>

bool isLetter(char symbol)
{
    if ((symbol >= 'A' && symbol <= 'Z') || (symbol >= 'a' && symbol <= 'z'))
        return true;
    return false;
}

char **toSubstrings(char *sentence)
{
    char *sentenceCopy1 = sentence;
    char *sentenceCopy2 = sentence;
    // while (*str) ... -> if (*str ) countSubstrings ++; --> char** words = new
    size_t countWords = 0;
    while (*sentence)
    {
        if (isLetter(*(sentence - 1)) == false && isLetter(*sentence) == true)
            countWords++;
        sentence++;
    }
    // now we know the exact number of arrays in our array
    unsigned wordLengths[countWords + 1] = {0};
    int wordNumber = 0;
    while (*sentenceCopy1)
    {
        if (isLetter(*sentenceCopy1) == true)
        {
            wordLengths[wordNumber]++;
            sentenceCopy1++;
        }
        if (isLetter(*sentenceCopy1) == false)
        {
            wordNumber++;
            sentenceCopy1++;
        }
    }
    // counting size of each word

    char **words = new char *[countWords + 1];
    for (size_t i = 0; i < wordNumber; i++)
    {
        words[i] = new char[wordLengths[i] + 1];
    }
    // initialized the matrix -> now fill

    unsigned wordIndex = 0;
    unsigned letterIndex = 0;
    while (*sentenceCopy2)
    {
        if (isLetter(*sentenceCopy2) == true)
        {
            words[wordIndex][letterIndex] = *sentenceCopy2;
            sentenceCopy2++;
        }
        if (isLetter(*sentenceCopy2) == false)
        {
            wordIndex++;
            sentenceCopy2++;
        }
    }

    return words;
}

int main()
{
    ////// xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

    return 0;
}