#include <iostream>
#include <vector>
using namespace std;

// PRE:  Una sequencia de vectors de punts al pla.
// POST: Escriure, per a cada vector
//       1) si hi ha dos punts diferents.
//       2) Si la suma de les coordenades x's coincideix o amb la de les coordenades y's
//       3) El baricentre, i si apareix o no al vector.
// NOTA: Les posicions comencen a 1

struct Punt {
    double x, y;
};

bool eq(const Punt& a, const Punt& b)
{
    return (a.x == b.x and a.y == b.y);
}

bool Lee(vector<Punt>& v)
{
    int n = v.size();
    bool dif = false;
    cin >> v[0].x >> v[0].y;
    for (int i = 1; i < n; ++i) {
        cin >> v[i].x >> v[i].y;
        if ((not dif) and (not eq(v[0], v[i])))
            dif = true;
    }
    return dif;
}

bool baricentre(const vector<Punt>& v, Punt& p)
{
    int n = v.size();
    p.x = v[0].x / n, p.y = v[0].y / n;
    for (int i = 1; i < n; ++i) {
        p.x += v[i].x;
        p.y += v[i].y;
    }
    int i = 0;
    while (i < n and (not eq(p, v[i])))
        ++i;
    return (i < n);
}

int main()
{
    cout.setf(ios::fixed);
    cout.precision(2);
    int n;
    while (cin >> n) {
        vector<Punt> v(n);
        Punt p;
        p.x = 0;
        p.y = 0;
        // leemos el vector de puntos y comprobmos 2 diferentes
        bool dif = Lee(v);
        bool bar = baricentre(v, p);
        cout << "baricentro: (" << p.x << "," << p.y << ")" << endl;
        if (dif and bar and p.x == p.y)
            cout << "vector normalizado" << endl;
        else {
            cout << "el vector no cumple la propiedad ";
            if (not dif)
                cout << "1" << endl;
            else if (p.x != p.y)
                cout << "2" << endl;
            else
                cout << "3" << endl;
        }
    }
}
