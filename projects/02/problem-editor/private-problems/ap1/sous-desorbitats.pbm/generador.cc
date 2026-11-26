#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Fitxa {
    int id;
    string nom;
    vector<int> nomines;
};

using BD = vector<Fitxa>;

int compare(const Fitxa& f1, const Fitxa& f2)
{
    int t1 = 0;
    int t2 = 0;
    for (int x : f1.nomines)
        t1 += x;
    for (int x : f2.nomines)
        t2 += x;
    if (t1 > t2)
        return -1;
    if (t1 < t2)
        return 1;
    if (f1.nomines.size() < f2.nomines.size())
        return -1;
    if (f1.nomines.size() > f2.nomines.size())
        return 1;
    int n = f1.nomines.size();
    int i = 0;
    while (i < n and f1.nomines[i] == f2.nomines[i])
        ++i;
    if (i == n) {
        if (f1.id < f2.id)
            return -1;
        else if (f1.id > f2.id)
            return +1;
        else
            return 0;
    } else {
        if (f1.nomines[i] > f2.nomines[i])
            return -1;
        else
            return 1;
    }
}

bool lessthan(const Fitxa& f1, const Fitxa& f2)
{
    int b = compare(f1, f2);
    if (b < 0)
        return true;
    return false;
}

void pinta(const Fitxa& f)
{
    cout << f.id << " ";
    cout << f.nom << " ";
    cout << f.nomines.size();
    for (int i = 0; i < int(f.nomines.size()); ++i) {
        cout << " " << f.nomines[i];
    }
    cout << endl;
}

bool ids(Fitxa f1, Fitxa f2)
{
    return f1.id < f2.id;
}

int main()
{
    int seed;
    cin >> seed;
    srand(seed);
    int n = rand() % 1000;
    BD data(n);
    for (int i = 0; i < n; ++i) {
        data[i].id = rand() % 10000000;
        data[i].nom = to_string(data[i].id);
        int totsou = rand() % 5000000;
        int partsou = -1;
        while (partsou < totsou) {
            int q = min(rand() % 100000, totsou - partsou);
            partsou += q;
            data[i].nomines.push_back(q);
        }
    }
    sort(data.begin(), data.end(), ids);
    for (int i = 1; i < n; ++i) {
        if (data[i].id == data[i - 1].id) {
            cout << "REPEATED ID; ABORTING" << endl;
            exit(1);
        }
    }
    sort(data.begin(), data.end(), lessthan);
    int p = rand() % n;
    pinta(data[p]);
    cout << endl;
    for (int i = 9; i < n; ++i) {
        pinta(data[i]);
    }
}
