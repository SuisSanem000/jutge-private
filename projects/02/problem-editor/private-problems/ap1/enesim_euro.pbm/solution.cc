#include <iostream>
#include <string>
using namespace std;

/*
Llegeix els elements d'una factura  i retorna aquell element
on s'ha gastat nesim_euro. Si no el troba, retorna "".
*/
string troba_element(int nesim_euro)
{
    double suma = 0.0;
    string trobat = ""; // desconegut
    string actual;
    cin >> actual;
    while (actual != "---") {
        double cost;
        cin >> cost;
        suma += cost;
        if (trobat == "" and suma >= nesim_euro) {
            trobat = actual;
        }
        cin >> actual;
    }
    return trobat;
}

/*
Llegeix la següent factura de l'entrada
i escriu com s'ha gastat nesim_euro.
*/
void processa_factura(int nesim_euro)
{
    string nom_factura;
    cin >> nom_factura;
    string element = troba_element(nesim_euro);
    if (element != "") {
        cout << "En la factura " << nom_factura << " l'euro " << nesim_euro << " s'ha gastat en " << element << "." << endl;
    } else {
        cout << "En la factura " << nom_factura << " no s'ha gastat l'euro " << nesim_euro << "." << endl;
    }
}

int main()
{
    int k, n;
    cin >> k >> n;
    for (int i = 0; i < k; ++i) {
        processa_factura(n);
    }
}
