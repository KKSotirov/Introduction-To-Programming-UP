#include <iostream>
using namespace std;

int main ()
{
    // int kilometers, tax = 3;
    // cout << "Please enter the traveled distance in kilometers. " << endl;
    // cin  >> kilometers;
     int km, km2;
    double price, price2, total;
    cin >> km;
    km2 = (km > 5) * 5 + (km <= 5) * km;
    price = km2 * 2.5;
    price2 = (km - km2) * 1.5;
    total = price + price2;
    bool check = total > 20;
    cout << ((check*0.1)*total) + total + 3 << "lv.";


   
    return 0;
}