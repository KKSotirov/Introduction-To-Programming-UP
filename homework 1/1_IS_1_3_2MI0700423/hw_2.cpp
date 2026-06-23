#include <iostream>
using std::cout;
using std::cin;
using std::endl;

        bool isPrime (unsigned number) {
            bool prime = true;

            for (int i = 2; i < (number/2); i++) {
                if (number % i == 0) prime = false;
             }
            return prime;
        }

        bool hasNoRepeatingDig (unsigned number) {
             int lastDig = number%10;
             unsigned original = number;

            for (;number > 0;) {
            do {
                number = number/10;
                if (number == 0) break;
                if (lastDig == (number%10)) return false;
            } while (number > 0);

            number = original/10;
            lastDig = number % 10;
            original = original / 10; 
            if (number == 0) return true;
        }
            return true;
        }

        int findSmallerUnique (unsigned number) {
            unsigned original;

            for (;;) {
            number--;
            original = number;
            if (hasNoRepeatingDig(number) == true && isPrime(number) == true) return original;
            else number = original;
        }
                return original;
        }

        int findBiggerUnique (int number) {
            unsigned original;

            for (;;) {
            number++;
            original = number;
            if (hasNoRepeatingDig(number) == true && isPrime(number) == true) return original;
            else number = original;
        }
                return original;
        }
        

int main () 
{
    unsigned number;
    cout << "Please enter a number.";
    cin >> number;

      if (hasNoRepeatingDig(number) == true && isPrime(number) == true)
       cout << "The entered number is already unique." << endl;

      else {
        if (abs(number - findBiggerUnique(number)) < abs(number - findSmallerUnique(number))) 
            cout << "Closest unique number is: " << findBiggerUnique(number) << endl;

        else cout << "Closest unique number is: " << findSmallerUnique(number) << endl;
     }

    return 0;
}