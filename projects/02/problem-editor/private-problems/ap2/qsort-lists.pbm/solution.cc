#include <iostream>
#include <list>
using namespace std;

list<int> concat(const list<int>& l1, int x, const list<int>& l2)
{
    list<int> result;
    for (int element : l1) {
        result.push_back(element);
    }
    result.push_back(x);
    for (int element : l2) {
        result.push_back(element);
    }
    return result;
}

list<int> qsort(const list<int>& lst)
{
    if (lst.size() <= 1) {
        return lst;
    } else {
        auto it = lst.begin();
        int pivot = *it;
        list<int> smaller, greater;
        for (++it; it != lst.end(); ++it) {
            (*it < pivot ? smaller : greater).push_back(*it);
        }
        return concat(qsort(smaller), pivot, qsort(greater));
    }
}

int main()
{
    list<int> lst;

    int x;
    while (cin >> x) {
        lst.push_back(x);
    }

    list<int> sorted = qsort(lst);

    for (int y : sorted) {
        cout << y << endl;
    }
}
