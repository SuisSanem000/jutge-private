
#include <iostream>
#include <vector>
using namespace std;

#include "player.hh"

vector<string> winners(vector<Player>::iterator ini, vector<Player>::iterator fin);

vector<Player> llegeix_jugadors() {
    vector<Player> v;
    Player p;
    while (cin >> p.name >> p.score) {
        v.push_back(p);
    }
    return v;
}

void escriu_jugadors(const vector<string>& w) {
    for (int i = 0; i < w.size(); i++) {
        cout << (i == 0 ? "" : " ") << w[i];
    }
    cout << endl;
}

int main() {
    vector<Player> v = llegeix_jugadors();

    // Cridem la funció d'interès
    vector<string> w = winners(v.begin(), v.end());

    escriu_jugadors(w);

    return 0;
}