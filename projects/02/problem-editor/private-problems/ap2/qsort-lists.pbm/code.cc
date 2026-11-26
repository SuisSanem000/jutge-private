#include <iostream>
#include <list>
using namespace std;

list<int> qsort(const list<int>& lst)
{
    ...
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

/*************************************************************************************

    Expliqueu aquí quin és el cost del vostre algorisme.

*************************************************************************************/