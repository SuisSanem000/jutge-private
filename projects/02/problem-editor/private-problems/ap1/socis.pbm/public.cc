#include <iostream>
#include <vector>

using namespace std;

struct Data {
    int dia;
    int mes;
    int any;
};

void llegir_data(Data& data)
{
    ...
}

struct Persona {
    string nom;
    int dni;
    Data naixament;
    string municipi;
};

void llegir_persona(Persona& persona)
{
    ...
}

struct Soci {
    int dni;
    bool junta;
    Data inscripcio;
};

void llegir_soci(Soci& soci)
{
    ...
}

using Persones = vector<Persona>;

using Socis = vector<Soci>;

// Retorna el nombre de socis que siguin a la junta i
// visquin en un municipi donat i hagin nascut a
// l'any donat o més tard.
//
// Precondició: persones i socis ordenats per dni
//
int nombre_de_socis_joves_a_la_junta_en_un_municipi(const Persones& persones, const Socis& socis, int any, const string& municipi)
{
    ...
}

int main()
{
    // llegir persones
    int np;
    cin >> np;
    Persones persones(np);
    for (Persona& persona : persones) {
        llegir_persona(persona);
    }

    // llegir socis
    int ns;
    cin >> ns;
    Socis socis(ns);
    for (Soci& soci : socis) {
        llegir_soci(soci);
    }

    // llegir paràmetres
    int any;
    cin >> any;
    string municipi;
    cin >> municipi;

    // escriure el resultat
    cout << nombre_de_socis_joves_a_la_junta_en_un_municipi(persones, socis, any, municipi);
}
