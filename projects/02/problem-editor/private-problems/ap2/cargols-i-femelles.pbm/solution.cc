#include <iostream>
#include <vector>

using namespace std;

struct Cargol {
    int ample; // private! 👀
};

struct Femella {
    int ample; // private! 👀
};

using Cargols = vector<Cargol>;

using Femelles = vector<Femella>;

// retorna un vector d'n cargols
Cargols llegir_cargols(int n)
{
    Cargols cargols(n);
    for (Cargol& c : cargols) {
        cin >> c.ample;
    }
    return cargols;
}

// retorna un vector d'n femelles
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

// concatena els elements d'esquerra, de mig i de dreta en desti.
// i.e.: desti = esquerra, mig, dreta
template <typename T>
void concatena(const vector<T>& esquerra, const T& mig, const vector<T>& dreta, vector<T>& desti)
{
    for (auto x : esquerra) {
        desti.push_back(x);
    }
    desti.push_back(mig);
    for (auto x : dreta) {
        desti.push_back(x);
    }
}

// Donats uns cargols i unes femelles seguint les regles de l'enunciat,
// els retorna ordenats els paràmetres cargols_ordenats i femelles_ordenades.
void ordenar(const Cargols& cargols, const Femelles& femelles, Cargols& cargols_ordenats, Femelles& femelles_ordenades)
{
    cargols_ordenats = {};
    femelles_ordenades = {};

    if (cargols.size() > 0) {
        Cargol cargol_mig = cargols[0]; // millor: random
        Femella femella_mig;
        Cargols cargols_petits, cargols_grans;
        Femelles femelles_petites, femelles_grans;

        // partició de les femelles
        for (Femella f : femelles) {
            int r = compara(cargol_mig, f);
            if (r == -1) {
                femelles_grans.push_back(f);
            } else if (r == 1) {
                femelles_petites.push_back(f);
            } else {
                femella_mig = f;
            }
        }

        // partició dels cargols
        for (Cargol c : cargols) {
            int r = compara(c, femella_mig);
            if (r == 1) {
                cargols_grans.push_back(c);
            } else if (r == -1) {
                cargols_petits.push_back(c);
            }
        }

        // recursivitat pels petits
        Cargols cargols_petits_ordenats;
        Femelles femelles_petites_ordenades;
        ordenar(cargols_petits, femelles_petites, cargols_petits_ordenats, femelles_petites_ordenades);

        // recursivitat pels grans
        Cargols cargols_grans_ordenats;
        Femelles femelles_grans_ordenades;
        ordenar(cargols_grans, femelles_grans, cargols_grans_ordenats, femelles_grans_ordenades);

        // fusió dels resultats
        concatena(cargols_petits_ordenats, cargol_mig, cargols_grans_ordenats, cargols_ordenats);
        concatena(femelles_petites_ordenades, femella_mig, femelles_grans_ordenades, femelles_ordenades);
    }
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
