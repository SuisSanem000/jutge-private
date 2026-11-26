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
    cin >> data.dia;
    cin >> data.mes;
    cin >> data.any;
}

struct Persona {
    string nom;
    int dni;
    Data naixament;
    string municipi;
};

void llegir_persona(Persona& persona)
{
    cin >> persona.nom;
    cin >> persona.dni;
    llegir_data(persona.naixament);
    cin >> persona.municipi;
}

struct Soci {
    int dni;
    bool junta;
    Data inscripcio;
};

void llegir_soci(Soci& soci)
{
    cin >> soci.dni;
    char c;
    cin >> c;
    soci.junta = c == 'S';
    llegir_data(soci.inscripcio);
}

using Persones = vector<Persona>;

using Socis = vector<Soci>;

// retorna el nombre de socis que siguin a la junta i visquin en un municipi donat i hagin nascut a l'any any_max o més tard
int nombre_de_socis_joves_a_la_junta_en_un_municipi(const Persones& persones, const Socis& socis, int any_max, const string& municipi)
{
    // prec: persones i socis ordenats per dni

    int i = 0; // índex de persona
    int j = 0; // índex de soci
    int c = 0; // comptador

    int np = persones.size();
    int ns = socis.size();

    while (i < np and j < ns) {
        if (persones[i].dni < socis[j].dni) {
            ++i;
        } else if (persones[i].dni > socis[j].dni) {
            ++j;
        } else {
            if (persones[i].naixament.any >= any_max and socis[j].junta and persones[i].municipi == municipi) {
                ++c;
            }
            ++i;
            ++j;
        }
    }

    return c;
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
    int any_max;
    cin >> any_max;
    string municipi;
    cin >> municipi;

    // escriure el resultat
    cout << nombre_de_socis_joves_a_la_junta_en_un_municipi(persones, socis, any_max, municipi);
}
