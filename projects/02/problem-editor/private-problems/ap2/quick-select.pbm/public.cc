#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

// Hoare's partition.
// Partitions $v[l..r]$ into $v[l..q,q+1..r]$ where $q$ is the returned value
// so that all elements in $v[l..q]$ are smaller or equal than all elements in $v[q+1..r]$.
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

// Sorts $v[l..r]$ using quick sort.
void quicksort(vector<int>& v, int l, int r)
{
    if (l < r) {
        const int q = partition(v, l, r);
        quicksort(v, l, q);
        quicksort(v, q + 1, r);
    }
}

// Returns the sum of the $k$ smallest elements of $v$.
int sum_smallest(vector<int> v, int k)
{
    int n = v.size();
    assert(k >= 0 and k <= n);
    quicksort(v, 0, n - 1);
    int s = 0;
    for (int i = 0; i < k; ++i)
        s += v[i];
    return s;
}

// Just a test
int main()
{
    cout << sum_smallest({ 4, 91929, 2, 4, 1 }, 3) << endl;
}
