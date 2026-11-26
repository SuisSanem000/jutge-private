
#include <list>
#include <map>
#include <string>
using namespace std;

list<pair<string, int> > all_pairs(map<string, int>& M) {
    list<pair<string, int> > L;
    map<string, int>::iterator it = M.begin();
    for (; it != M.end(); it++) {
        L.push_back(*it);
    }
    return L;
}
