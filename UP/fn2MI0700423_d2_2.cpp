/**
 *
 * Solution to homework assignment 2
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2025/2026
 *
 * @author Kaloyan Sotirov
 * @idnumber 2MI0700423
 * @task 2
 * @compiler GCC - 6.3.0
 *
 */
#include <iostream>
const size_t MAX_ARR_SIZE = 100;

long long countVariations(char *str)
{
    // key idea -> by giving more letters to generate substrings, if there are more than 1 occurance of a letter it is inevitable to onstruct a duplicate we have alredy counted. This duplicate must be substracted from the total amount of variations
    long long total = 1;
    long long lastCount[26] = {0};
    // 26 letters --> array with each letters' frequency, (currently at 0 for each)

    while (*str)
    {
        int letter = *str - 'a';
        long long newTotal = 2 * total - lastCount[letter];
        // by subtracting lastCount[letter] we are essentially removing the duplicates, if there are any
        lastCount[letter] = total;
        total = newTotal;
        str++;
    }

    total = total - 1; // we can cross out k-1 max letters, not k, meaning we do not count the empty string
    return total;
}

int main()
{
    char *str = new char[MAX_ARR_SIZE];
    std::cout << "Please enter string : " << std::endl;
    std::cin >> str;
    std::cout << "The amount of strings that can be made by crossing out letters is: " << countVariations(str) << std::endl;

    delete[] str;
    return 0;
}