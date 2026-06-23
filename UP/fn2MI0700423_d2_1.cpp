/**
 *
 * Solution to homework assignment 2
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2025/2026
 *
 * @author Kaloyan Sotirov
 * @idnumber 2MI0700423
 * @task 1
 * @compiler GCC - 6.3.0
 *
 */
#include <iostream>

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

size_t calcNewSize(char *str1, char *str2)
{
    size_t newSize = strLen(str1) + strLen(str2);
    return newSize;
}

void concatStr(char *newStr, char *str1, char *str2)
{
    while (*str1)
    {
        *newStr = *str1;
        newStr++;
        str1++;
    }
    while (*str2)
    {
        *newStr = *str2;
        newStr++;
        str2++;
    }
    *newStr = '\0';
    // this function gives value to the new str by concatenating str1 and str2 together
}

void countOccurances(char *newStr, int letterOccurances[])
{
    // this array is with length 26, representing our 26 letters in alphabet
    // currently every positions value is 0, in our case meaning - we have 0 occurances of element at index 0 (logically a)
    // ... up to element at index[26] ('z')...

    // now we needt o count how many times each letter is found
    //  after that check if there is a valid palindrome available, if yes - construct it
    for (size_t i = 0; newStr[i] != '\0';)
    {
        letterOccurances[newStr[i] - 'a']++;
        i++;
        // essentially we are counting how many times each letter is found --> 97 in ascii is pos of 'a'
    }
}

bool isPalindromePossible(char *newStr, int letterOccurances[])
{
    size_t newSize = strLen(newStr);
    size_t uniqueMiddleSymb = 0;
    if (newSize % 2 == 0)
    {
        for (size_t i = 0; i < 26; i++)
        {
            if (letterOccurances[i] % 2 != 0)
                return false;
            // this means we have found a letter that is present in an uneven amount of times, which means there
            // cannot be a palindrome with these letters.
        }
    }
    if (newSize % 2 != 0)
    {
        for (size_t i = 0; i < 26; i++)
        {
            if (letterOccurances[i] % 2 != 0)
            {
                uniqueMiddleSymb++;
            }
        }
    }
    if (uniqueMiddleSymb > 1)
        return false;
    // this essentially means that if we have more than one unique element to be placed in the middle - we cant construct a palindrome
    // ---------------------------------------------------
    return true;
}

char *constructPalindrome(char *newStr, int letterOccurances[])
{
    size_t newSize = strLen(newStr);
    size_t left = 0;
    size_t right = newSize - 1;
    for (size_t letterIndex = 0; letterIndex < 26; letterIndex++)
    {
        // we are going to be filling spaces from the left side and the right side simultioniously
        while (letterOccurances[letterIndex] >= 2)
        {
            newStr[left] = 'a' + letterIndex;
            newStr[right] = 'a' + letterIndex;
            right--;
            left++;
            letterOccurances[letterIndex] = letterOccurances[letterIndex] - 2;
        }
    }
    // this covers the case when we have an even size, but if we have an uneven string, we must add the unique middle element
    // ==>
    for (size_t letterIndex = 0; letterIndex < 26; letterIndex++)
    {
        if (letterOccurances[letterIndex] == 1)
        {
            newStr[left] = 'a' + letterIndex;
            // the for looop helps us cycle throught the letters and find the one letter that still has a single occurance left, and not written in the palindrome
            letterOccurances[letterIndex]--;
        }
    }

    newStr[newSize] = '\0';
    return newStr;
}

char *getNewStr(char *str1, char *str2)
{
    size_t newSize = calcNewSize(str1, str2);
    char *newStr = new char[newSize + 1];
    concatStr(newStr, str1, str2);
    int letterOccurances[26] = {0};
    // this array is with length 26, representing our 26 letters in alphabet
    // currently every index has value 0, meaning next to every index from 0 to 26 (in our case this representing our letters from the alphabet) there are 0 occurances.

    // We need to count how many times each letter is found
    //  after that check if there is a valid palindrome available, if yes - construct it
    countOccurances(newStr, letterOccurances);
    // now letterOccurances should be filled with all the info about our letter occurances
    // we have 2 possibilites from now on : newSize is even or uneven
    // if even -> every letter must be found an even amount of times
    // if uneven -> every letter EXCEPT ONE must be found an even amount of times
    // this essentially means that if we have more than one unique element to be placed in the middle - we cant construct a palindrome

    bool isPalPossible = isPalindromePossible(newStr, letterOccurances);
    if (isPalPossible == false)
        return nullptr;
    else
    {
        return constructPalindrome(newStr, letterOccurances);
    }
}

void getStr(char *str)
{
    while (*str)
    {
        std::cout << *str;
        str++;
    }
}

int main()
{
    // the program receives two already allocated strings
    char *const str1 = new char[5];
    str1[0] = 'c';
    str1[1] = 'o';
    str1[2] = 't';
    str1[3] = 't';
    str1[4] = '\0';
    char *const str2 = new char[4];
    str2[0] = 'c';
    str2[1] = 'a';
    str2[2] = 'a';
    str2[3] = '\0';
    //--------------------
    char *palindrome = getNewStr(str1, str2);
    if (palindrome == nullptr)
        std::cout << "Cannot construct a palindrome." << std::endl;
    else
        getStr(palindrome);

    delete[] palindrome;
    delete[] str1;
    delete[] str2;
    return 0;
}