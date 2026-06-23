#include <iostream>
#include <cmath>
using std::cout;
using std::cin;
using std::endl;

       int getSize (unsigned number) {
            int length = 0;
            for (; number != 0; ) {
                number = number/10;
                length++;
            }
            return length;
        }

        int concatenate (unsigned number1, unsigned number2) {
            return (number1*pow(10,getSize(number2)) + number2);
    }

        int sort (unsigned concatenatedNumber) {
            int sortedNumber = 0;

            for (int i = 9; i >= 0; i--) {
                int temp = concatenatedNumber;
                while (temp > 0) {
                    if (temp%10 == i) sortedNumber = sortedNumber * 10 + i;
                    temp = temp/10;
                }
            }
            return sortedNumber;
        }

int main () 
{
    unsigned number1, number2;
    size_t numberOfPairs;
    unsigned greatest = 0, secondGreatest = 0;
    unsigned  concatenatedNumber = 0;

    cout << "Please enter number of pairs;" << endl;
    cin >> numberOfPairs;

    for (size_t i = 1; i <= numberOfPairs; i++) {
        cout << "Please enter a pair. "; 
        cin >> number1 >> number2;
        concatenatedNumber = concatenate(number1, number2);
        int sortedNumber = sort(concatenatedNumber);
        if (i==1) {
            greatest = sortedNumber;
            secondGreatest = sortedNumber;
        } 
        else {
            if (sortedNumber > greatest) {
                secondGreatest = greatest;
                greatest = sortedNumber;
            }
            else if (sortedNumber > secondGreatest || secondGreatest == greatest) secondGreatest = sortedNumber;
        }
    }
        cout << "Biggest sorted number = " << greatest << endl;
        cout << "Second biggest sorted number = " << secondGreatest << endl;
    return 0;
}
