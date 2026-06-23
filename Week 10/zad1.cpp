#include <iostream>

    int strLength (const char *str) {
     
        int length = 0;
        while (*str != '\0') {
            length ++;
            str++;
        }
         return length;
    } 
    
int main() {
    
    const char *str = "Please send help";
    std::cout << strLength(str);

    return 0;
}