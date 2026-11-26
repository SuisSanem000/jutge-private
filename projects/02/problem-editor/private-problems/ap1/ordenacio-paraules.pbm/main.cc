#include <iostream>
#include <string>
#include <vector>
using namespace std;

// procediment que cal implementar
void ordenar(vector<string>&);

int main()
{
    // llegir paraules en un vector
    vector<string> paraules;
    {
        string paraula;
        while (cin >> paraula) {
            paraules.push_back(paraula);
        }
    }

    // ordenar el vector amb la funció que cal implementar
    ordenar(paraules);

    // escriure el vector
    for (const string& paraula : paraules) {
        cout << paraula << endl;
    }
    return 0;
}
