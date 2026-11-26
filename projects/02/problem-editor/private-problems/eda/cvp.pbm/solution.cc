#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stack>

using namespace std;

class Circuit {

private:

    map<string, int> cables;  // cable ids to numbers
    vector< vector<int> > G;  // digraph representing the circuit
    vector< vector<int> > H;  // reverse of G
    vector<string> T;         // types of the gates
    vector<int> ge;           // input degree of G
    int no;                   // number of output cables
    int ni;                   // number of input cables

    string not_g(string a) {
        return (a == "T")?"F":"T";
    }

    string and_g(string a, string b) {
        return (a == "F")?"F":((b == "F")?"F":"T");
    }

    string or_g(string a, string b) {
        return not_g(and_g(not_g(a), not_g(b)));
    }

    void add_vertex(string id) {
        cables[id] = G.size();
        G.push_back(vector<int>());
        H.push_back(vector<int>());
        T.push_back("UNDEF");
        ge.push_back(0);
    }


public:

    Circuit() {
        string x;
        cin >> x >> x;
        while (x != "END") {
            add_vertex(x);
            cin >> x;
        }
        no = G.size();
        cin >> x >> x;
        while (x != "END") {
            add_vertex(x);
            cin >> x;
        }
        ni = G.size() - no;
        cin >> x;
        while (x != "END") {
            string o; cin >> o;
            if (cables.count(o) == 0) add_vertex(o);
            T[cables[o]] = x;
            string i; cin >> i;
            if (cables.count(i) == 0) add_vertex(i);
            G[cables[i]].push_back(cables[o]);
            H[cables[o]].push_back(cables[i]);
            ge[cables[o]]++;
            if ((x == "AND") or (x == "OR")) {
                string j; cin >> j;
                if (cables.count(j) == 0) add_vertex(j);
                G[cables[j]].push_back(cables[o]);
                H[cables[o]].push_back(cables[j]);
                ge[cables[o]]++;
            }
            cin >> x;
        }
    }

    int num_inputs() { return ni; }

    int num_outputs() { return no; }

    vector<string> eval(const vector<string>& I) {
        vector<string> O = T;
        vector<int> aux = ge;
        stack<int> S;
        for (int i = 0; i < ni; ++i) {
            int g = no + i;
            O[g] = I[i];
            for (int j = 0; j < int(G[g].size()); ++j) {
                int h = G[g][j];
                --aux[h]; if (aux[h] < 1) S.push(h);
            }
        }
        while (not S.empty()) {
            int g = S.top(); S.pop();
            if (O[g] == "NOT") O[g] = not_g(O[H[g][0]]);
            else if (O[g] == "AND") O[g] = and_g(O[H[g][0]], O[H[g][1]]);
            else if (O[g] == "OR") O[g] = or_g(O[H[g][0]], O[H[g][1]]);
            else cerr << "UALA";
            for (int j = 0; j < int(G[g].size()); ++j) {
                int h = G[g][j];
                --aux[h]; if (aux[h] < 1) S.push(h);
           }
        }
        return O;
    }

};

int main() {
    Circuit C;
    vector<string> I(C.num_inputs());
    while (cin >> I[0]) {
        for (int j = 1; j < C.num_inputs(); ++j) cin >> I[j];
        vector<string> O = C.eval(I);
        for (int j = 0; j < C.num_outputs() - 1; ++j) cout << O[j] << " ";
        cout << O[C.num_outputs() - 1] << endl;
    }
}

