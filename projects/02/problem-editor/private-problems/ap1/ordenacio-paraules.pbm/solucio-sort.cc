#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

using P = pair<string, int>;
using VP = vector<P>;

bool es_minuscula(char c)
{
    return c >= 'a' and c <= 'z';
}

bool abans(P x, P y)
{
    bool bx = es_minuscula(x.first[0]);
    bool by = es_minuscula(y.first[0]);
    if (bx != by)
        return bx;
    int sx = x.first.size();
    int sy = y.first.size();
    if (sx != sy)
        return sx < sy;
    return x.second < y.second;
}

vector<string> ordena_sense_sort(const vector<string>& V)
{
    int n = V.size();
    VP T(n);
    for (int i = 0; i < n; ++i)
        T[i] = P(V[i], i);
    sort(T.begin(), T.end(), abans);
    vector<string> R(n);
    for (int i = 0; i < n; ++i)
        R[i] = T[i].first;
    return R;
}

vector<string> ordena_sense_sort_bo(const vector<string>& V)
{
    vector<vector<string>> minus(11), majus(11);
    for (string s : V) {
        if (islower(s[0]))
            minus[s.size()].push_back(s);
        else
            majus[s.size()].push_back(s);
    }
    vector<string> R;
    for (int i = 1; i <= 10; ++i)
        for (string s : minus[i])
            R.push_back(s);
    for (int i = 1; i <= 10; ++i)
        for (string s : majus[i])
            R.push_back(s);
    return R;
}

void prova(vector<string>& V, bool& primer)
{
    vector<string> V1 = ordena_sense_sort(V);
    vector<string> V2 = ordena_sense_sort_bo(V);
    if (V1 == V2)
        cout << "OK\n";
    else {
        cout << "WA";
        if (primer) {
            primer = false;
            for (string s : V1)
                cout << ' ' << s;
        }
        cout << '\n';
    }
}

int main()
{
    int inc, n;
    while (cin >> inc >> n) {
        bool primer = true;
        vector<string> V;
        if (inc == 1)
            prova(V, primer);
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            V.push_back(s);
            if (V.size() % inc == 0)
                prova(V, primer);
        }
    }
}
