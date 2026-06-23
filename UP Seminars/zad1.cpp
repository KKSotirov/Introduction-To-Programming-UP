#include <iostream>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;

unsigned findDigitCount (unsigned N) {
    if (N==0) return 1;
    int counter = 0;
    while (N!=0) {
        counter ++;
        N/=10;
    }
    return counter;
}


int findFirstDig (unsigned N) {
    int count = findDigitCount (N);

    return N/(pow(10,count));
}


bool isSubNum (unsigned N, unsigned k) {
    int count = findDigitCount (N);
     int newN = N - N*(pow(10,count));
    if (k >= N) return false;
    
    if (k == N%10 || k == N/(pow(10,count))) return false;
    // PROVERQVAME DALI CHISLOTO k NE E NQKOQ OT KRAINITE CIFRI
    for (int i = 0; i < count; i++) {
        if (k == newN) return true;
        else newN = newN - newN*(pow(10,count));
    }
    // PROBVAME DALI SE SUDURZHA AKO MAHAME CHISLA OTPRED
    for (int i = 0; i < count; i++) {
        if (k == newN) return true;
        else newN = newN/10;
    }
    // PROBVAME DALI SE SUDURZHA KATO MAHAME CHISLA OTZAD
    for (int i = 0; i < count; i++) {
        if (k == newN) return true;
        else {
            newN = newN - newN*(pow(10,count));
            newN = newN/10;
            } 
    }
    // PROBVAME DALI SE SUDURZHA KATO MAHAME CHISLA EDNOVREMENNO OTPRED I OTZAD
    return false;
}

int main ()
{
    int N, k;
    cout << "Please enter N." << endl;
    cin >> N;
    cout << "Please enter k." << endl;
    cin >> k;

    cout << "N contains k:  " << isSubNum(N,k);



    return 0;
}