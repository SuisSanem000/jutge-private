#include <iostream>
#include <vector>
using namespace std;

const char BOLA1 = 'B';
const char BOLA2 = 'b';
const char RES = '.';
const char PAS = '=';

typedef vector<vector<char>> Tauler;

struct Bola {
    int x_ant, y_ant;
    int x_act, y_act;
    int x_seg, y_seg;
};

void emplena_tauler(Tauler& t, Bola& b)
{
    b.x_ant = b.y_ant = -1;

    cin >> b.x_act >> b.y_act;
    t[b.x_act][b.y_act] = BOLA1;

    if (b.x_act == 0)
        b.x_seg = b.x_act + 1;
    else
        b.x_seg = b.x_act - 1;

    if (b.y_act == 0)
        b.y_seg = b.y_act + 1;
    else
        b.y_seg = b.y_act - 1;

    int x, y;
    cin >> x >> y;
    t[x][y] = BOLA2;
}

bool topa_banda(const Tauler& t, const Bola& b)
{
    int n = t.size();
    int m = t[0].size();
    return (b.x_act == 0 or b.x_act == n - 1 or b.y_act == 0 or b.y_act == m - 1);
}

bool topa_cantonada(const Tauler& t, const Bola& b)
{
    int n = t.size();
    int m = t[0].size();
    return ((b.x_act == 0 or b.x_act == n - 1) and (b.y_act == 0 or b.y_act == m - 1));
}

void moure_fins_xocar(Tauler& t, Bola& b)
{
    int n = t.size();
    int dx = b.x_seg - b.x_act;
    int dy = b.y_seg - b.y_act;

    bool banda = false;
    bool cantonada = false;
    bool bola = false;
    while (not banda and not cantonada and not bola) {
        b.x_ant = b.x_act;
        b.y_ant = b.y_act;
        b.x_act = b.x_seg;
        b.y_act = b.y_seg;

        banda = topa_banda(t, b);
        cantonada = topa_cantonada(t, b);
        bola = (t[b.x_act][b.y_act] == BOLA2);

        b.x_seg = b.x_act;
        b.y_seg = b.y_act;

        if (not banda) {
            b.x_seg += dx;
            b.y_seg += dy;

        } else if (not cantonada) {

            // Banda superior
            if (b.x_act == 0) {
                ++b.x_seg;
                if (b.y_ant < b.y_act)
                    ++b.y_seg;
                else
                    --b.y_seg;
            }
            // Banda inferior
            else if (b.x_act == n - 1) {
                --b.x_seg;
                if (b.y_ant < b.y_act)
                    ++b.y_seg;
                else
                    --b.y_seg;
            }
            // Banda esquerra
            else if (b.y_act == 0) {
                ++b.y_seg;
                if (b.x_ant < b.x_act)
                    ++b.x_seg;
                else
                    --b.x_seg;
            }
            // Banda dreta
            else {
                --b.y_seg;
                if (b.x_ant < b.x_act)
                    ++b.x_seg;
                else
                    --b.x_seg;
            }
        }
        t[b.x_ant][b.y_ant] = PAS;
        t[b.x_act][b.y_act] = BOLA1;
    }
}

void escriu(const Tauler& t)
{
    int n = t.size();
    int m = t[0].size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            cout << t[i][j];
        cout << endl;
    }
    cout << endl;
}

void escriu(const Bola& b)
{
    cout << "(" << b.x_act << "," << b.y_act << ")";
}

int main()
{
    int n, m;
    while (cin >> n >> m) {
        Tauler t(n, vector<char>(m, RES));
        Bola b;
        emplena_tauler(t, b);

        bool aturar = false;
        bool carambola = false;
        int xocs = 0;
        while (not aturar and not carambola) {
            moure_fins_xocar(t, b);

            if (topa_cantonada(t, b))
                aturar = true;

            else if (topa_banda(t, b)) {
                escriu(b);
                ++xocs;
                if (xocs > 3)
                    aturar = true;
            } else {
                if (xocs < 3)
                    aturar = true;
                else
                    carambola = true;
            }
        }
        if (carambola)
            cout << ": si" << endl;
        else
            cout << ": no" << endl;
        escriu(t);
    }
}
