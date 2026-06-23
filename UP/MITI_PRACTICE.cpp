#include <iostream>

void initArray(char* str, int size) {
    while (size-- > 0) {
        std::cin >> *str;
        str++;
    }
    *str = '\0';
}

void getArray(const char* str) {
    while (*str) {
        std::cout << *str++;
    }
    std::cout << std::endl;
}

int getArrayLength(const char* str) {
    int length = 0;
    while (*str++) length++;
    return length;
}

void copyString (char* str, char* strCopy) {
    while (*str) {
        *strCopy = *str;
        str++;
        strCopy++;
    }
    *strCopy = '\0';
}

void getReverseString(char* dest, const char* src) {
    int len = getArrayLength(src);
    src += len - 1;

    while (len-- > 0) {
        *dest++ = *src--;
    }
    *dest = '\0';
}

    void duplicateString(char* dest, const char* src) {
    const char* start = src;

    while (*src) {
        *dest++ = *src++;
    }
    src = start;

    while (*src) {
        *dest++ = *src++;
    }
    *dest = '\0';
}

    char elementAtIndex (char* str, unsigned index) {
        unsigned count = 0;
        while (*str) {
        if (count == index) return *str;
        else {
            str++;
            count++;
        }
    }
    }

    void delElementAtIndex (char* str, unsigned index) {
         unsigned count = 0;
        while (*str) {

        if (count == index) {
            while (*str) {
             *str = *(str+1);
             str++;
            }
            return;
        }
        else {
            str++;
            count++;
        }
    }        
    }

    void appendElement (char* str, char appended) {
        while (*str) {
            str++;
        }
        *str = appended;
        *(str+1) = '\0';
    }

    bool isPalindrome (char* str, char* reversed) {
//if (str == getReverseString(reversed, str)) return true;      else return false; 
        while (*str) {
            if (*str != *reversed) return false;
            str++;
            reversed++;
        }
        return true;
    }

    int numberOfOccurances (char* str, char occuringChar) {
        int count = 0;
        while (*str) {
            if (*str == occuringChar) count++;
            str++;
        }
        return count;
    }


    void insertElementAtDesiredIndex (char* str, unsigned indexToInsert, char inserted) {
        int count = 0;
        char tmp;
        while (*str) {
            if (indexToInsert == count) {
                tmp = *str;
                *str = inserted;
                *(str+1) = tmp;
                str++;
                while (*str) {
                    *str = *(str+1);
                    str++;
                }
            } return;
            str++;
        }
    }
int main() {
    size_t size;
    unsigned index, indexToInsert;
    char appended, occuringChar, inserted;
    std::cout << "Please enter size of array:\n";
    std::cin >> size;
    std::cout << "Please enter searched index: \n";
    std::cin >> index;
    std::cout << "Please enter an element to be appended at the end of the string: " << std::endl;
    std::cin >> appended;
    std::cout << "Please enter an element to be searched of its occurances: " << std::endl;
    std::cin >> occuringChar;
    std::cout << "Please enter the index at which to insert a character: " << std::endl;
    std::cin >> indexToInsert;
    std::cout << "Please enter the character to insert at the desired index: " << std::endl;
    std::cin >> inserted;

    char* str = new char[size + 3];
    initArray(str, size);
    getArray(str);
    char* strCopy = new char[size + 1];
    copyString(str,strCopy);

    char* reversed = new char[size + 1];
    getReverseString(reversed, str);
    getArray(reversed);
    char* duplicated = new char[size * 2 + 1];
    duplicateString(duplicated, str);
    getArray(duplicated);
    std::cout << "The element at the desired index is: " << elementAtIndex(str,index) << std::endl;
    delElementAtIndex(str,index);
    getArray(str);
    appendElement(str,appended);
    getArray(str);
    std::cout << "Altered string is palindrome: " << std::boolalpha << isPalindrome(str, reversed) << std::endl;
    std::cout << "Original string is palindrome: " << std::boolalpha << isPalindrome(strCopy, reversed) << std::endl;
    std::cout << "Number of occurances of element '" << occuringChar << "' in altered string is : " << numberOfOccurances(str,occuringChar) << std::endl;
    std::cout << "Number of occurances of element '" << occuringChar << "' in original string is : " << numberOfOccurances(strCopy,occuringChar) << std::endl;

    insertElementAtDesiredIndex (str, indexToInsert, inserted);
    getArray(str);

    

    delete[] str;
    delete[] reversed;
    delete[] duplicated;
    return 0;
}
