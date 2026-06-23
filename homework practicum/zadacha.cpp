#include <iostream>

void initMatrix (char** matrix, size_t rows, size_t cols) {
    for (size_t i = 0; i < rows; i++) {
        matrix[i] = new char[cols];
        for (size_t j = 0; j < cols; j++) {
            // std::cout << "Please enter element at pos: " << i <<"," << j << ": ";
            std::cin >> matrix[i][j];
        }
        std::cout << std::endl;
    }
}
void getMatrix (char** matrix, size_t rows, size_t cols) {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
     //       std::cout << "Element at pos " << i << "," << j << ": " << matrix[i][j] << std::endl;
              std::cout << matrix[i][j];
        }   
        std::cout << std::endl;
    }
}

void deleteMatrix(char** matrix, size_t rows) {
    for (size_t i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

size_t strLen (char* words) {
    size_t wordLen = 0;
    while (*words) {
        wordLen++;
        words++;
    }
    return wordLen;
}

 void calculateRowsPointsForWord(char** matrix, size_t i, size_t j, size_t &currIndex, char* words, size_t &wordPoints, size_t wordLen, size_t cols){
        while (j + currIndex < cols && currIndex < wordLen && matrix[i][j + currIndex] == words[currIndex]) {
            // povtarqme cikula dokato elementite na bukvata ne produlzhavat da se namirat v redovete na matrix   
            // gledame sledvashtata bukva v dumata i uvelichavame broqt na namerenite
            wordPoints = wordPoints + (i*(j+currIndex));
            currIndex++;
            // gledame sledvashtata bukva v dumata i uvelichavame broqt na namerenite

            //smqtame stoinostta na bukvata i preminavame na sledvashtata bukva v matricata, iskame i sledvashtata bukva da suvpada
        }
    }

    void calculateColsPointsForWord(char** matrix, size_t i, size_t j, size_t &currIndex, char* words, size_t &wordPoints, size_t wordLen, size_t rows){
        while (currIndex < wordLen && i + currIndex < rows && matrix[i + currIndex][j] == words[currIndex]) {
            wordPoints = wordPoints + ((i+currIndex)*j);
            currIndex++;
        }
    }

    void calculateMainDiagonalsPointsForWord (char** matrix, size_t i, size_t j, size_t &currIndex, char* words, size_t &wordPoints, size_t wordLen, size_t rows, size_t cols) {
        while (currIndex < wordLen && i + currIndex < rows && j + currIndex < cols && matrix[i+currIndex][j+currIndex] == words[currIndex]) {
            wordPoints = wordPoints + ((j+currIndex)*(i+currIndex));
            currIndex++;
        }
    }

    void calculateReverseDiagonalsPointsForWord (char** matrix, size_t i, size_t j, size_t &currIndex, char* words, size_t &wordPoints, size_t wordLen, size_t rows, size_t cols) {
        while (currIndex < wordLen && i + currIndex < rows && j >= currIndex && matrix[i + currIndex][j - currIndex] == words[currIndex]) {
            wordPoints = wordPoints + ((j-currIndex)*(i+currIndex));
            currIndex++;
        }
    }
    
      void printPointsForWord(size_t wordLen, char* words, size_t wordPoints) {  
        for (size_t k = 0; k < wordLen; k++) {
            std::cout << words[k];
            // obhozhdame cqlata duma
        }
        std::cout << " -> " << wordPoints << std::endl;
    }

void aggregatePoints (char** matrix, char* words, size_t rows, size_t cols, size_t numbers, int arrayOfPointValues[]) {
    size_t wordLen = strLen(words);
    bool found = false;
    // obhojdame matricata napulno
        for (size_t z = 0; z < numbers; z++) {
        // int arrayOfPointValues[numbers + 1];
        for (size_t i = 0; i < rows; i++) {
             size_t currIndex = 0;
             size_t wordPoints = 0;
            //
            for (size_t j = 0; j + wordLen <= cols; j++) {
                // index za poziciite na bukvite na dumata
                currIndex = 0;
                wordPoints = 0;
                found = false;

                calculateRowsPointsForWord(matrix, i, j, currIndex, words, wordPoints, wordLen, cols);
                if (currIndex == wordLen) {
                    found = true;
                }

                //sled proverka po redove, izvezhdame ako e namerena duma i nulirame currIndex i wordPoints i produlzhavame rabotata sus sushtata poziciq, povikvaiki i drugite funkcii, kato taka vednuzh stupili na edna poziciq, shte q proverim dali obrazuva duma po vsichki nachini
                currIndex = 0;
                wordPoints = 0;

                calculateColsPointsForWord(matrix,i,j,currIndex,words,wordPoints,wordLen,rows);
                if (currIndex == wordLen) {
                    
                }

                calculateMainDiagonalsPointsForWord(matrix,i,j,currIndex,words,wordPoints,wordLen,rows,cols);
                if (currIndex == wordLen) {

                }

                if (j >= wordLen - 1) {
                calculateReverseDiagonalsPointsForWord(matrix, i, j, currIndex, words, wordPoints, wordLen, rows, cols);
                if (currIndex == wordLen) {

                }
                if (currIndex != wordLen || found == false) {
                    
                }
        }
       }
      }
     }
    }

int main () {
    size_t rows, cols, numbs, maximumSizeOfWord;
    std::cout << "Please enter number of rows: ";
    std::cin >> rows;
    std::cout << "Please enter number of cols: ";
    std::cin >> cols;    
    char**matrix = new char*[rows];
    std::cout << "Please enter number of words to be searched: ";
    std::cin >> numbs;
    //
    initMatrix(matrix,rows,cols);
    int arrayOfPointValues[numbs + 1];

    maximumSizeOfWord = (rows>cols) ? rows : cols;

    char**words = new char*[numbs];
    for (size_t i = 0; i < numbs; i++) {
    words[i] = new char[maximumSizeOfWord + 1];
    std::cin >> words[i];
}
    for (size_t i = 0; i < numbs; i++) {
      aggregatePoints(matrix, words[i], rows, cols, numbs);
      // za vsqka duma broim tochkite
}
    

    deleteMatrix(matrix,rows);
    for (size_t i = 0; i < numbs; i++) delete[] words[i];
    delete[] words;

    return 0;

}