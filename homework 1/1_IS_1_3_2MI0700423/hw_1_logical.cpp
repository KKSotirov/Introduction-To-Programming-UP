#include <iostream>
#include <cmath>
using std::cout;
using std::cin;
using std::endl;


    void drawShape (int N) {
        for (size_t i = 1; i<= N; i++) {
            for (size_t j=1; j<=i; j++) {
                cout << j;
       }
            cout << endl;
    }
        for (size_t k = (N-1); k > 0; k--) {
            for (size_t l = 1; l <= k; l++) {
                cout << l << " " ;
            }
            cout << endl;
         }
    }


    void pushBeginning (int N) {
        for (size_t i = 0; i <((80-3*N)/2); i++) cout << " ";
    }

    void pushEnd (int N) {
        for (size_t k = ((80+3*N)/2); k <= 80; k++) cout << " ";
    }
    


int main () {
    int N;
    cout << "N = " ;
    cin >> N;
 
      for (size_t rows = 0; rows < 25; rows++) {
        for (size_t columns = 0; columns < 80; columns++ ) {
            if (columns < (80 - 3*N)/2 )  cout << " ";
            if (columns == 79) {
                rows++;
                cout << endl;
            }
            
            if (columns >= (82 - 3*N)/2 && columns < (82 - N)/2 && rows == (13 - N)) {
                for (size_t i = 1; i<= N; i++) {
                    // pushBeginning(N);
                    for (size_t j=1; j<=i; j++) {
                        cout << j;
                        columns++;
                        // pushEnd(N);
                    }
                    cout << endl;
                    rows++;
                    pushBeginning(N);
                }
                for (size_t k = (N-1); k > 0; k--) {
                    //pushBeginning(N);
                    for (size_t l = 1; l <= k; l++) {
                        cout << l;
                        columns++;
                        //pushEnd(N);
                    }
                    cout << endl;
                    rows++;
                    pushBeginning(N);
                        // break;
                }
                columns = (82 - N)/2;
                rows = 13 - N;
    }
                        //LQVA FIGURA

                 if (columns >= (82 - N)/2 && columns < (82 + N)/2 && rows == (13 - N)) {
                     for (size_t m = 1; m<= (2*N-1); m++) {
                         for (size_t n=N; n>=N; n--) {
                             if (m==n) {
                                cout <<"---";
                                columns = columns + 3;
                                       }
                             else {
                                cout << "   ";
                                columns = columns + 3;
                                  }
                         }
                             cout << endl;
                     }
                //     //Razdelitel
                columns == (82 + N)/2;
                rows = 13 - N;
                 }

                 if (columns >= (82 + N)/2 && columns < (82 + 3*N)/2 && rows == (13 - N)) {
                   for (size_t i = 1; i <= N; i++) {
                        for (size_t j = N; j > 0; j--) {
                            if (i>=j) {
                                cout << j ;
                                columns++;
                                      }       
                            else {
                                cout << " ";
                                columns++;
                                 }
                        }
                            cout << endl;
                            rows++;
                    }
                        for (size_t k = N; k > 0; k--) {
                        for (size_t l = N; l > 0; l--) {
                            if (k>l) { 
                                cout << l ;
                                columns++;
                                     }
                            else {
                                cout << " ";
                                columns++;
                                 }   
                        }
                            cout << endl;
                            rows++;
                    }
                //   DQSNA FIGURA     
//                pushEnd(N);               
                    columns = 80;
                    rows = 25;
                 }
                    if (columns == 80 && rows == 25) break;
}
    }
    return 0;
}
