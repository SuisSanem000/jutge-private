// Utilitzeu aquest fitxer com a plantilla.

struct Fitxa {
    int id;
    string nom;
    vector<int> nomines;
};

using BD = vector<Fitxa>;

void split(const BD& data, const Fitxa& f, vector<string>& up, vector<string>& down)
{
}

int find(const vector<int>& v, int x, int l, int r)
// Pre:
// el vector d'enters v esta ordenat creixentment,
// 0 <= l <= v.size(),
// -1 <= r <= v.size() - 1,
// si l <= r, llavors x esta a v[l,...,r].
// Post:
// retorna una posicio de v que conte x.
{
    if (l > r) {
        return l;
    } else {
        int m = (l + r) / 2;
        if (x < v[m]) {
            return find(v, x, l, m - 1);
        } else if (x > v[m]) {
            return find(v, x, m + 1, r);
        } else {
            return m;
        }
    }
}

// Programa principal amb l'entrada/sortida del problema
// i la crida a split.

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
