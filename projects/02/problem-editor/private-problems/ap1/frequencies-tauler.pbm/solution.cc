#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> Freqs;
typedef vector<Freqs> MatFreq; 

const int DIGIT_RANGE = 10;

//pre: matf is non-empty
//post: initializes matf to zero
//info: unnecessary initialization to zero (done by default) (c++)
void init_to_zero(MatFreq& matf) {
    int m = matf.size();
    int n = matf[0].size();
    for (int i = 0; i < m; ++i)
        for (int j= 0; j < n; ++j) matf[i][j] = 0;
}

//pre: m and n are greater than zero
//post: returns the frequecy matrix correspoding to input m x n board
MatFreq get_freqs(int m, int n) {
    MatFreq matf(DIGIT_RANGE, Freqs(n));
    init_to_zero(matf);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int digit;
            cin >> digit;
            ++matf[digit][j];
        }
    }
    return matf;
}

//matf is non-empty
//prints matf
void write_results(const MatFreq& matf) {
    int m = matf.size();
    int n = matf[0].size();
    for (int i = 0; i < m; ++i) {
        cout << matf[i][0];
        for (int j = 1; j < n; ++j) 
            cout << ' ' << matf[i][j];
        cout << endl;
    }
    cout << endl;
}


int main() {
    int m;
    int n;
    while (cin >> m >>  n) {
        MatFreq matf = get_freqs(m, n);
        write_results(matf);
    }
}
