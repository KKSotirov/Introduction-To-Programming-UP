// ;
// Напишете функция, която приема символен низ(състоящ се само от букви) и връща нов динамично заделен низ, който представлява "компресирана" версия на входа.Компресията работи, като заменя всяка поредица от еднакви последователни символи със самия символ, следван от броя на повторенията му.

//     ;
// Изисквания :

//     ;
// Трябва да изчислите точно колко памет е нужна за новия низ(напр."A12" заема 3 байта + 1 за терминиращия символ).;
// Числото след буквата може да бъде многоцифрено(напр.ако имаме 100 символа 'A').
// AAAb -> A3b

// 1.count successive chars
// 2. int to string - 10 ->'1''0'
// 3. calcMemToAlloc() - AAAb -> A3b -> 3+1=4 TO ALLOCATE
// 4. concatString(char* word, char* suffix)

int countDigits(int count)
{
    int current = count;
    int count = 0;
    while (current >= 0)
    {
        current /= 10;
    }
    return count;
}

char *intToString(int count)
{
    int digitsCount = countDigits(count);
    char *result = new char[digitsCount + 1];

    while (digitsCount > 0)
    {
        int currentDigit = count / (10 ^ (digitsCount - 1)); // 1
        char digitChar = currentDigit + '0';                 // '1'
        concatCharToString(result, digitChar);               // res = ['1']
        count = count % (10 ^ (digitsCount - 1));            // count = 11 % (10^(2-1)) = 1
        digitsCount--;                                       // digitsCount = 1;
    }
    // count - 11
    //  result - ['1','1']
    return result;
}

int strLen(char *source)
{
    char *current = source;
    int count = 0;
    while (current != nullptr)
    {
        count++;
        current++;
    }
    return count;
}
void concatStringToString(char *&source, char *suffix)
{
    int fstLen = strLen(source);
    int sndLen = strLen(source);
    char *result = new char[fstLen + sndLen + 1];

    char *current = source;
    int currentPos = 0;
    while (current != nullptr)
    {
        result[currentPos] = *current;
        current++;
        currentPos++;
    }
    current = suffix;
    while (current != nullptr)
    {
        result[currentPos] = *current;
        current++;
        currentPos++;
    }

    result[currentPos] = '\0';
    delete[] source;
    source = result;
}

void concatCharToString(char *&source, char suffix)
{
    int fstLen = strLen(source);
    char *result = new char[fstLen + 1 + 1];

    char *current = source;
    int currentPos = 0;
    while (current != nullptr)
    {
        result[currentPos] = *current;
        current++;
        currentPos++;
    }
    result[currentPos] = suffix;
    currentPos++;
    result[currentPos] = '\0';
    delete[] source;
    source = result;
}

char *compress(char *word)
{
    // word = AAAB
    char *current = word;
    char *result = new char[calcResSize(word) + 1];
    while (current != nullptr)
    {
        char currentSymbol = *current;
        char *curr = current;
        int count = 0;

        while (*curr == currentSymbol)
        {
            count++;
            curr++;
        }

        char *occurrences = intToString(count);
        concatCharToString(result, currentSymbol);
        concatStringToString(result, occurrences);

        // Iter1:  A3 in result
        // Iter2:  A3B1 in result

        if (current != curr)
        {
            current = curr - 1;
        }
    }
    return result;
}

int calcResSize(char *word)
{
    // word = AAAB
    char *current = word;
    int resultSize = 0;
    while (current != nullptr)
    {
        char currentSymbol = *current;
        char *curr = current;
        int count = 0;

        while (*curr == currentSymbol)
        {
            count++;
            curr++;
        }
        // iter1: currentSymbol = A; count = 3
        int digitsCount = countDigits(count);
        resultSize += digitsCount + 1;
    }
    return resultSize;
}