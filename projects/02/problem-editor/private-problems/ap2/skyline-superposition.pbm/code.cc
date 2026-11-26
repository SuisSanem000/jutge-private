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

Skyline skyline_superposition(const Skyline& s1, const Skyline& s2)
{

    ...
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        Skyline s1 = read_skyline();
        Skyline s2 = read_skyline();
        Skyline ss = skyline_superposition(s1, s2);
        print_skyline(ss);
    }
}
