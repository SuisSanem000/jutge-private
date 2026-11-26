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
    Skyline s; // The result
    int i1 = 0, i2 = 0; // Indices to visit the two skylines
    int h1 = 0, h2 = 0; // Current height of the two skylines
    int h = 0; // Current height of the result

    while (i1 < s1.size() and i2 < s2.size()) {
        int x1 = s1[i1].x;
        int x2 = s2[i2].x;
        int newx;
        if (x1 < x2) {
            newx = x1;
            h1 = s1[i1].y;
            ++i1;
        } else if (x1 > x2) {
            newx = x2;
            h2 = s2[i2].y;
            ++i2;
        } else {
            newx = x1;
            h1 = s1[i1].y;
            h2 = s2[i2].y;
            ++i1;
            ++i2;
        }

        int newh = max(h1, h2);
        if (newh != h)
            s.push_back({ newx, newh });
        h = newh;
    }

    while (i1 < s1.size()) {
        s.push_back(s1[i1]);
        ++i1;
    }

    while (i2 < s2.size()) {
        s.push_back(s2[i2]);
        ++i2;
    }

    return s;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        Skyline s1 = read_skyline();
        Skyline s2 = read_skyline();
        Skyline s = skyline_superposition(s1, s2);
        print_skyline(s);
    }
}
