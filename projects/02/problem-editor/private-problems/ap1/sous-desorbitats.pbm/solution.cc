#include <iostream>
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

int find(const BD& data, const Fitxa& f, int l, int r)
// Pre:
// el vector de fitxes data esta ordenat creixentment,
// 0 <= l <= data.size(),
// -1 <= r <= data.size() - 1,
// si l <= r, llavors f esta a data[l,...,r].
// Post:
// retorna una posicio de data que conte f.
{
    if (l > r)
        return l;
    int m = (l + r) / 2;
    int b = compare(f, data[m]);
    if (b < 0)
        return find(data, f, l, m - 1);
    else if (b > 0)
        return find(data, f, m + 1, r);
    else
        return m;
}

void split(const BD& data, const Fitxa& f,
    vector<string>& up, vector<string>& down)
{
    int n = data.size();
    int p = find(data, f, 0, n);
    up = vector<string>(p);
    down = vector<string>(n - p - 1);
    for (int i = 0; i < p; ++i)
        up[i] = data[i].nom;
    for (int i = p + 1; i < n; ++i)
        down[i - p - 1] = data[i].nom;
}

int main()
{
    int id;
    BD data;
    Fitxa f0;
    int c = 0;
    while (cin >> id) {
        Fitxa f;
        f.id = id;
        cin >> f.nom;
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            int nomina;
            cin >> nomina;
            f.nomines.push_back(nomina);
        }
        if (c == 0)
            f0 = f;
        else
            data.push_back(f);
        ++c;
    }
    vector<string> up, down;
    split(data, f0, up, down);
    int n1 = up.size();
    int n2 = down.size();
    cout << data.size() << " " << n1 << " " << n2 << endl;
    cout << endl;
    for (int i = 0; i < n1; ++i) {
        cout << up[i] << endl;
    }
    cout << endl;
    for (int i = 0; i < n2; ++i) {
        cout << down[i] << endl;
    }
}
