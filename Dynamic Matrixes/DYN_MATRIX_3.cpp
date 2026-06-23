#include <iostream>

bool isWord(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        return true;
    return false;
}

int charToInt(char ch)
{
    return ch - 'A';
}

char *smallestLexicographicly(char *sentence)
{
    char *ptr = sentence;
    // copy of sentence
    size_t countOfWords = 0;
    bool inWord = false;

    while (*ptr)
    {
        if (isWord(*ptr) == true)
        {

            if (inWord == false)
            {
                // this indicates the start of a new word
                countOfWords++;
                inWord = true;
            }
        }
        else if (isWord(*ptr) == false)
            inWord = false;
        ptr++;
    }
    // veche imame broqt na dumite v izrechenieto
    //
    char **words = new char *[countOfWords + 1];
    size_t wordSize = 0;
    ptr = sentence;
    size_t wordIndex = 0;
    while (*ptr)
    {
        // if in word -> while = broi kolko golqma e dumata, sled while-a zadelqme mqsto v matricata za tazi duma i vuv for q kopirame. Sled koeto mestim ptr i nulirame size

        while (*ptr && isWord(*ptr) == true)
        {
            wordSize++;
            ptr++;
        }
        ptr = ptr - wordSize;
        words[wordIndex] = new char[wordSize + 1];
        for (size_t i = 0; i < wordSize; i++)
        {
            // words[wordIndex] = ptr[i];
        }

        ptr++;
    }
}

// 1. Напишете функция, която приема символен низ и връща лексикографски най-малката дума.
//               Вход	                                                     Изход
//"Things  do not change; we Change." - Henry David Thoreau	                Change