#include "atzar.cc"
#include <iostream>
#include <set>
#include <vector>
using namespace std;

atzar A(0);

const int MAX = 1e6;

using VS = vector<string>;
using SS = set<string>;

bool primer = true;

string par()
{
    int m = A.uniforme(1, 10);
    char c = (A.uniforme(0, 1) ? 'a' : 'A');
    string s;
    while (m--)
        s += A.uniforme(0, 25) + c;
    return s;
}

bool ok(string s)
{
    int m = s.size();
    if (m < 1 or m > 10)
        return false;
    if (islower(s[0])) {
        for (char c : s)
            if (not islower(c))
                return false;
    } else {
        for (char c : s)
            if (not isupper(c))
                return false;
    }
    return true;
}

void print(int inc, const VS& V)
{
    int n = V.size();
    if (inc < 1 or inc > n) {
        cerr << "pifia!!!" << endl;
        return;
    }

    if (n < 1 or n > MAX) {
        cerr << "pifia!!!" << endl;
        return;
    }

    SS S;
    for (string s : V) {
        if (not ok(s) or S.find(s) != S.end()) {
            cerr << "pifia!!!" << endl;
            return;
        }
        S.insert(s);
    }

    if (primer)
        primer = false;
    else
        cout << endl;
    cout << inc << ' ' << n << endl;
    for (string s : V)
        cout << s << endl;
}

void test(int inc, int n)
{
    SS S;
    while ((int)S.size() < n)
        S.insert(par());
    VS T(S.begin(), S.end());
    vector<int> perm = A.permutacio(n);
    VS V(n);
    for (int i = 0; i < n; ++i)
        V[i] = T[perm[i]];
    print(inc, V);
}

int main()
{
    test(MAX / 40, MAX);
}
