#include <iostream>
#include <string>
#include <vector>
using namespace std;

int number_of_rotations(const vector<int>& v);

int main()
{
    string type;
    cin >> type;
    if (type == "explicit") {
        int n;
        while (cin >> n) {
            vector<int> v(n);
            for (int i = 0; i < n; ++i)
                cin >> v[i];
            cout
                << number_of_rotations(v)
                << endl;
        }
    } else if (type == "implicit") {
        int n, r, t;
        while (cin >> n >> r >> t) {
            vector<int> v(n);
            for (int i = 0; i < n; ++i) {
                v[i] = (i - r + n + n) % n;
            }
            /*
            for (int i = 0; i < n; ++i) {
                cerr << v[i] << " ";
            }
            cerr << endl;
            */
            int s = 0;
            for (int i = 0; i < t; ++i) {
                s = (s + number_of_rotations(v)) % 784536;
            }
            cout << s << endl;
        }
    }
    return 0;
}
