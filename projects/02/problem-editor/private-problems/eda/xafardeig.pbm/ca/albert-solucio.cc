#include <iostream>
#include <map>
#include <string>

using namespace std;

typedef map<string, string>::iterator iter;

int main() {

    map<string, string> M;
    string s;
    while (cin >> s) {
        if (s == "liats") {
            string p1, p2;
            cin >> p1 >> p2;
            if (M[p1] != "") M[M[p1]] = "";
            if (M[p2] != "") M[M[p2]] = "";
            M[p1] = p2;
            M[p2] = p1;
        }
        else {
            cout << "PARELLES:" << endl;
            for (iter it = M.begin(); it != M.end(); ++it) {
	        if (it->second != "" and it->first < it->second) {
                    cout << it->first << " " << it->second << endl;
                }
            }
            cout << "SOLS:" << endl;
            for (iter it = M.begin(); it != M.end(); ++it) {
	        if (it->second == "") cout << it->first << endl;
            }
            cout << "----------" << endl;
        }
    }

}
