#include <iostream>

void initMatrix(char **matrix, size_t rows, size_t cols)
{
    for (size_t i = 0; i < rows; i++)
    {
        matrix[i] = new char[cols];
        for (size_t j = 0; j < cols; j++)
        {
            std::cin >> matrix[i][j];
        }
        std::cout << std::endl;
    }
}

void deleteMatrix(char **matrix, size_t rows)
{
    for (size_t i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

size_t strLen(char *words)
{
    size_t wordLen = 0;
    while (*words)
    {
        wordLen++;
        words++;
    }
    return wordLen;
}

void calculateRowsPointsForWord(char **matrix, size_t i, size_t j, size_t &currIndex, char *words, size_t &wordPoints, size_t wordLen, size_t cols)
{
    while (j + currIndex < cols && currIndex < wordLen && matrix[i][j + currIndex] == words[currIndex])
    {
        // povtarqme cikula dokato elementite na bukvata ne produlzhavat da se namirat v redovete na matrix
        // gledame sledvashtata bukva v dumata i uvelichavame broqt na namerenite
        wordPoints = wordPoints + (i * (j + currIndex));
        currIndex++;
        // gledame sledvashtata bukva v dumata i uvelichavame broqt na namerenite

        // smqtame stoinostta na bukvata i preminavame na sledvashtata bukva v matricata, iskame i sledvashtata bukva da suvpada
    }
}

void calculateColsPointsForWord(char **matrix, size_t i, size_t j, size_t &currIndex, char *words, size_t &wordPoints, size_t wordLen, size_t rows)
{
    while (currIndex < wordLen && i + currIndex < rows && matrix[i + currIndex][j] == words[currIndex])
    {
        wordPoints = wordPoints + ((i + currIndex) * j);
        currIndex++;
    }
}

void calculateMainDiagonalsPointsForWord(char **matrix, size_t i, size_t j, size_t &currIndex, char *words, size_t &wordPoints, size_t wordLen, size_t rows, size_t cols)
{
    while (currIndex < wordLen && i + currIndex < rows && j + currIndex < cols && matrix[i + currIndex][j + currIndex] == words[currIndex])
    {
        wordPoints = wordPoints + ((j + currIndex) * (i + currIndex));
        currIndex++;
    }
}

void calculateReverseDiagonalsPointsForWord(char **matrix, size_t i, size_t j, size_t &currIndex, char *words, size_t &wordPoints, size_t wordLen, size_t rows, size_t cols)
{
    while (currIndex < wordLen && i + currIndex < rows && j >= currIndex && matrix[i + currIndex][j - currIndex] == words[currIndex])
    {
        wordPoints = wordPoints + ((j - currIndex) * (i + currIndex));
        currIndex++;
    }
}

void printPointsForWord(char *words, size_t wordPoints)
{
    for (size_t i = 0; words[i] != '\0'; i++)
    {
        std::cout << words[i];
        // obhozhdame cqlata duma
    }
    std::cout << " -> " << wordPoints << std::endl;
}

size_t aggregateTotalPoints(char **matrix, char *word, size_t rows, size_t cols)
{
    size_t wordLen = strLen(word);
    size_t totalPoints = 0;

    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            size_t currIndex = 0;
            size_t wordPoints = 0;
            // suzdavame promenlivi:
            // wordPoints za tochkite na duma, namerena po edin nachin (red,kolona ili diagonal)
            // totalPoints, koqto she sudurzha vsichkite tochki na edna duma, dori kogato tq bude namerena nqkolko puti (da kazhem vednuzh po red i vednuzh po diagonal)
            // currIndex e kluchova, zashtoto tova e ednovremenno poziciqta, na koqto sme pri proverkite i sushto taka chrez neq proverqvame dali edna duma e napulno namerena. (ako wordLen (dulzhinata na dumata) e ravna na currIndex, toest vsichkite bukvi sa otkriti po daden kriterii, to tazi duma e v matricata). Sushto taka iskame predi vikaneto na nov kriterii za otkrivane v matricata da nulirame currIndex i wordPoints, za da zapochvame proverkata otnovo ot nachaloto na dumata i za da otkriem otnovo chastichnata suma (otnovo, wordPoints e sumata na tochki po edinichen kriterii).
            calculateRowsPointsForWord(matrix, i, j, currIndex, word, wordPoints, wordLen, cols);
            if (currIndex == wordLen)
                totalPoints = totalPoints + wordPoints;
            // pri otkritie po redove, dobavqme tochkite na dumata v totalPoints i produlzhavame da tursim dali tq shte bude otkrita i po drugi kriterii v matricata ni
            currIndex = 0;
            wordPoints = 0;
            // nulirame currIndex i wordPoints predi proverkata po nov kriterii, za da obhodim cqlata duma ot nuleva poziciq
            calculateColsPointsForWord(matrix, i, j, currIndex, word, wordPoints, wordLen, rows);
            if (currIndex == wordLen)
                totalPoints = totalPoints + wordPoints;

            currIndex = 0;
            wordPoints = 0;
            calculateMainDiagonalsPointsForWord(matrix, i, j, currIndex, word, wordPoints, wordLen, rows, cols);
            if (currIndex == wordLen)
                totalPoints = totalPoints + wordPoints;
            // sushtata logika produlzhava za vsichki kriterii
            currIndex = 0;
            wordPoints = 0;
            if (j >= wordLen - 1)
            {
                // za obratnite diagonali iskame da zapochnem proverkata, kogato purvata poziciq e stignala do dqsnata chast na matricata
                calculateReverseDiagonalsPointsForWord(matrix, i, j, currIndex, word, wordPoints, wordLen, rows, cols);
                if (currIndex == wordLen)
                    totalPoints = totalPoints + wordPoints;
            }
        }
    }

    return totalPoints;
    // vrushtame stoinostta na suotvetnata duma, kato ako tq ne bude namerena, nqma da se izpulni nikoi ot kriteriite i stoinostta shte ostane 0 ot red 72
}

void sortDescending(char **words, int *pointValuesForWords, size_t numbs)
{
    for (size_t i = 0; i < numbs; i++)
    {
        for (size_t j = 0; j < numbs - i - 1; j++)
        {
            // cikula 'i' postavq stoinostite na pravilnite im mesta, a cikula 'j' sravnqva vseki dve posledovatelni stoinosti
            if (pointValuesForWords[j] < pointValuesForWords[j + 1])
            {
                // ako po-golqmo chislo e na sledvashta poziciq, smenqme gi
                int tempPoints = pointValuesForWords[j];
                pointValuesForWords[j] = pointValuesForWords[j + 1];
                pointValuesForWords[j + 1] = tempPoints;

                // sushtoto pravim i za dumite, na koito otgovarqt tezi stoinosti
                char *tempWord = words[j];
                words[j] = words[j + 1];
                words[j + 1] = tempWord;
            }
        }
    }
}

int main()
{
    size_t rows, cols, numbs, maximumSizeOfWord;
    std::cout << "Please enter number of rows: ";
    std::cin >> rows;
    std::cout << "Please enter number of cols: ";
    std::cin >> cols;
    char **matrix = new char *[rows];
    std::cout << "Please enter number of words to be searched: ";
    std::cin >> numbs;

    std::cout << "Please initialize matrix: " << std::endl;
    initMatrix(matrix, rows, cols);
    maximumSizeOfWord = (rows > cols) ? rows : cols;

    std::cout << "Please enter searched words: " << std::endl;
    char **words = new char *[numbs];
    for (size_t i = 0; i < numbs; i++)
    {
        words[i] = new char[maximumSizeOfWord + 1];
        std::cin >> words[i];
    }

    int *pointValuesForWords = new int[numbs];
    for (size_t i = 0; i < numbs; i++)
    {
        pointValuesForWords[i] = aggregateTotalPoints(matrix, words[i], rows, cols);
    }
    // suhranqvame vsichki tochki na dumite v masiv

    sortDescending(words, pointValuesForWords, numbs);
    // veche sme sortirali dumite, sprqmo stoinostite im v nizhodqsht red ==> izvezhdame gi
    for (size_t i = 0; i < numbs; i++)
        printPointsForWord(words[i], pointValuesForWords[i]);
    // ostava da iztriem dinamichno zadelenata pamet
    deleteMatrix(matrix, rows);
    for (size_t i = 0; i < numbs; i++)
        delete[] words[i];

    delete[] words;
    delete[] pointValuesForWords;
    return 0;
}