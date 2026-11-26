#include <iostream>
#include <list>
using namespace std;

list<int> merge(const list<int>& l1, const list<int>& l2)
{
    list<int> lst;
    auto i1 = l1.begin();
    auto i2 = l2.begin();
    while (i1 != l1.end() and i2 != l2.end()) {
        if (*i1 <= *i2) {
            lst.push_back(*i1);
            ++i1;
        } else {
            lst.push_back(*i2);
            ++i2;
        }
    }
    for (; i1 != l1.end(); ++i1) {
        lst.push_back(*i1);
    }
    for (; i2 != l2.end(); ++i2) {
        lst.push_back(*i2);
    }
    return lst;
}

void split(const list<int>& lst, list<int>& l1, list<int>& l2)
{
    auto it = lst.begin();
    while (it != lst.end()) {
        l1.push_back(*it);
        ++it;
        if (it != lst.end()) {
            l2.push_back(*it);
            ++it;
        }
    }
}

list<int> msort(const list<int>& lst)
{
    if (lst.size() <= 1) {
        return lst;
    } else {
        list<int> l1, l2;
        split(lst, l1, l2);
        return merge(msort(l1), msort(l2));
    }
}

int main()
{
    list<int> lst;

    int x;
    while (cin >> x) {
        lst.push_back(x);
    }

    list<int> sorted = msort(lst);

    for (int y : sorted) {
        cout << y << endl;
    }
}
