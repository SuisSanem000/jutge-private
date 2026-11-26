#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> Parell;

bool is_fine(vector< vector<char> >& M, int x, int y) {
    if (M[x][y] == 'X') return false;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
	    if (M[x + i][y + j] == 'F') return false;
        }
    }
    return true;
}

bool can_reach(vector< vector<char> >& M, int x, int y) {

    vector<int> D(4); D[0] = D[1] = 0; D[2] = 1; D[3] = -1;
    vector<int> E(4); E[0] = 1; E[1] = -1; E[2] = E[3] = 0;

    queue<Parell> Q;
    if (is_fine(M, x, y)) Q.push(Parell(x, y));
    M[x][y] = 'X';
    while (not Q.empty()) {
        Parell p = Q.front(); Q.pop();
        for (int i = 0; i < 4; ++i) {
	    x = p.first + D[i];
            y = p.second + E[i];
            if (is_fine(M, x, y)) {
	        if (M[x][y] == 'B') return true;
                Q.push(Parell(x, y));
                M[x][y] = 'X';
            }
        }
    }
    return false;

}

int main() {

    int f, c;
    while (cin >> f >> c) {
        int x, y;
        vector< vector<char> > M(f, vector<char>(c));
        for (int i = 0; i < f; ++i) {
	    for (int j = 0; j < c; ++j) {
	        cin >> M[i][j];
                if (M[i][j] == 'P') { x = i; y = j; }
            }
        }
        if (can_reach(M, x, y)) cout << "si" << endl;
        else cout << "no" << endl;
    }

}
