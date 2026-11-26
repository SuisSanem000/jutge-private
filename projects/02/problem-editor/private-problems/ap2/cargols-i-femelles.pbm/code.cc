/******************************************************************************************


                ------------------------------------------------
                EXPLIQUEU L'ESTRATÈGIA DEL VOSTRE ALGORISME AQUÍ
                ------------------------------------------------


*******************************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

// defineix el tipus cargol
struct Cargol {
    int ample; // privat! 👀
};

// defineix el tipus femella
struct Femella {
    int ample; // privat! 👀
};

// defineix el tipus vector de cargols
using Cargols = vector<Cargol>;

// defineix el tipus vectors de femelles
using Femelles = vector<Femella>;

// retorna un vector d'n cargols llegit de l'entrada
Cargols llegir_cargols(int n)
{
    Cargols cargols(n);
    for (Cargol& c : cargols) {
        cin >> c.ample;
    }
    return cargols;
}

// retorna un vector d'n femelles llegit de l'entrada
Femelles llegir_femelles(int n)
{
    Femelles femelles(n);
    for (Femella& f : femelles) {
        cin >> f.ample;
    }
    return femelles;
}

// escriu un vector de cargols
void escriure_cargols(const Cargols& cargols)
{
    int n = cargols.size();
    if (n > 0) {
        cout << cargols[0].ample;
        for (int i = 1; i < n; ++i) {
            cout << ' ' << cargols[i].ample;
        }
    }
    cout << endl;
}

// escriu un vector de femelles
void escriure_femelles(const Femelles& femelles)
{
    int n = femelles.size();
    if (n > 0) {
        cout << femelles[0].ample;
        for (int i = 1; i < n; ++i) {
            cout << ' ' << femelles[i].ample;
        }
    }
    cout << endl;
}

// compara un cargol amb una femella:
//      si el cargol és més estret que la femella, retorna -1
//      si el cargol encaixa amb la femella, retorna 0
//      si el cargol és més ample que la femella, retorna 1
int compara(Cargol cargol, Femella femella)
{
    return cargol.ample < femella.ample ? -1 : cargol.ample > femella.ample;
}

// Donats uns cargols i unes femelles seguint les regles de l'enunciat,
// els retorna ordenats els paràmetres cargols_ordenats i femelles_ordenades.
void ordenar(const Cargols& cargols, const Femelles& femelles, Cargols& cargols_ordenats, Femelles& femelles_ordenades)
{
    cargols_ordenats = {};
    femelles_ordenades = {};

    if (cargols.size() == 0)
        return;

    // ----------------------------------------------------------------------------
    // COMPLETEU LA RESTA DEL CODI D'AQUESTA ACCIÓ AQUÍ
    // ----------------------------------------------------------------------------
}

int main()
{
    int n;
    while (cin >> n) {

        // llegir cargols i femelles
        Cargols cargols = llegir_cargols(n);
        Femelles femelles = llegir_femelles(n);

        // ordenar cargols i femelles
        Cargols cargols_ordenats;
        Femelles femelles_ordenades;
        ordenar(cargols, femelles, cargols_ordenats, femelles_ordenades);

        // escriure sortida
        escriure_cargols(cargols_ordenats);
        escriure_femelles(femelles_ordenades);
    }
}
