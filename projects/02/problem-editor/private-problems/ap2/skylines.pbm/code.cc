#include <iostream>
#include <vector>

using namespace std;

// Structure to represent a point in a 2D space
struct Point {
    int x, y;
};

// A skyline is a vector of Points sorted by the x coordinate
using Skyline = vector<Point>;

Skyline read_skyline()
{
    int n;
    cin >> n;
    Skyline s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i].x >> s[i].y;
    }
    return s;
}

void print_skyline(const Skyline& s)
{
    const int n = s.size();
    cout << n;
    for (int i = 0; i < n; ++i) {
        cout << ' ' << s[i].x << ' ' << s[i].y;
    }
    cout << endl;
}

Skyline skyline_superposition(const Skyline& s1, const Skyline& s2) {

    ...

}

Skyline skyline(const vector<Skyline>& skylines)
{

    ...
}

int main()
{
    int s;
    cin >> s;
    vector<Skyline> skylines(s);
    for (Skyline& sl : skylines) {
        sl = read_skyline();
    }
    print_skyline(skyline(skylines));
}
