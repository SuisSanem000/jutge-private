#include <iostream>
using namespace std;
#include <map>
#include "heap.hh"

int main() {
    map<string, pro2::Heap<int>> donacions;
    int llindar, donacio;
    string empresa;
    bool eleccions_netes = true;

    cin >> llindar;
    while (eleccions_netes && cin >> empresa >> donacio) {
        donacions[empresa].push(donacio);
    }
    for (auto i = donacions.begin(); i != donacions.end(); i++) {
        int total;
        for (int j = 0; j < 3; j++) {
            if (!(*i).second.empty()) {
                total += (*i).second.top();
                (*i).second.pop();
            }
        }
        if (total > llindar) {
            cout << (*i).first << endl;
            eleccions_netes = false;
        }
    }

    if (eleccions_netes) {
        cout << "eleccions netes!" << endl;
    }

    return 0;
}


