#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& v, int l, int r)
{
    const int x = v[l];
    int i = l - 1;
    int j = r + 1;
    for (;;) {
        while (x < v[--j])
            ;
        while (v[++i] < x)
            ;
        if (i >= j)
            return j;
        swap(v[i], v[j]);
    }
}

void quicksel(vector<int>& v, int l, int r, int k)
{
    if (l < r) {
        const int q = partition(v, l, r);
        if (k <= q)
            quicksel(v, l, q, k);
        else
            quicksel(v, q + 1, r, k);
    }
}

int sum_smallest(vector<int> v, int k)
{
    int n = v.size();
    assert(k >= 0 and k <= n);
    quicksel(v, 0, n - 1, k);
    int s = 0;
    for (int i = 0; i < k; ++i)
        s += v[i];
    return s;
}
