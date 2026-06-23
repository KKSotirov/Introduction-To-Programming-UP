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
int countOccurances (char** matrix, size_t rows, size_t cols, char occuring) {
    int count = 0;
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            if (matrix[i][j] == occuring) count++;
        }
    }
    return count;
}
void deleteMatrix(char** matrix, size_t rows) {
    for (size_t i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}
char** transposeMatrix (char** matrix, size_t rows, size_t cols) {
    char** transposed = new char*[cols];

    for (size_t i = 0; i < cols; i++) {
        transposed[i] = new char[rows];
        for (size_t j = 0; j < rows; j++) {
            transposed[i][j] = matrix[j][i];
        }
    }
    return transposed;
}

bool isSymmetric (char**matrix, char** transposedMatrix, size_t rows, size_t cols) {
    for (size_t i = 0; i < rows; i++) {
        for(size_t j = 0; j < cols; j++) {
            if (matrix[i][j] != transposedMatrix[i][j]) return false;
        }
    }
    return true;
}
int main () {
    size_t rows, cols;
    char occuring;
    std::cout << "Please enter number of rows: ";
    std::cin >> rows;
    std::cout << "Please enter number of cols: ";
    std::cin >> cols;    
    std::cout << "Please enter which element to search for occurances: ";
    std::cin >> occuring;

    char** matrix = new char*[rows];
    initMatrix(matrix,rows,cols);
    std::cout << "The entered matrix is: " << std::endl;
    getMatrix(matrix,rows,cols);
    std::cout << "Count of occurance of element: " << occuring << " = " << countOccurances(matrix,rows,cols,occuring) << std::endl;
    //(transposedMatrix, cols, rows);
    char** transposedMatrix = transposeMatrix(matrix,rows,cols);
    std::cout << "The transposed matrix is: " << std::endl;
    getMatrix(transposedMatrix, cols, rows);
    std::cout << "The matrix is symmetrical: " << std::boolalpha << isSymmetric(matrix,transposedMatrix,rows,cols) << std::endl;

    return 0;
}