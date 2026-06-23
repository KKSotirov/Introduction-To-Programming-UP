#include <iostream>
#include <cmath>

    bool isDigit (char c) {
        if (c >= 48 && c < 58) return true;
        return false;
    }
    bool isUpperCaseLetter (char c) {
        if (c >= 65 && c < 91) return true;
        return false;
    }
    bool isLower (char c) {
        if (c >= 97 && c < 123) return true;
        return false;
    }
    bool isAlpha (char c) {
        if (c >= 97 && c < 123 || c >= 65 && c < 91) return true;
        return false;
    }
    bool isAlnum (char c) {
        if (c >= 97 && c < 123 || c >= 65 && c < 91 || c >= 48 && c < 58) return true;
        return false;
    }
    void capitalize (char c) {
        if (c >= 97 && c < 123) std::cout << (char)toupper(c);
            else std::cout << c;
    }   
    void makeLower (char c) {
        if (c >= 65 && c < 91) std::cout << (char)tolower(c); 
            else std::cout << c;
    }
    int parseInt (char c) {
        if (c >= 48 && c < 58) return c - '0';
        return -1;
    }
    void toChar (int number) {
        if (number >= 0 && number <256) std::cout <<"character: " << (char)number;
        else std::cout << "/0";
    }
    double myLog (unsigned base) {
        return log(base);
    }
    int myPow (int number, unsigned power) {
        return pow(number,power);
    }
    double myCeil (double number) {
        return ceil(number);
    }
    double myFloor (double number) {
        return floor(number);
    }
    double myAbs (double number) {
        return abs(number);
    }
    
int main () 
{
    // char character;
    // std::cin >> character;
    // int ch = parseInt(character);
    // std::cout << "chisloto e : " << ch ;
    int a;
    std::cin >> a;
    toChar(a);


    return 0;
}
