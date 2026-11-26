#include <iostream>
using namespace std;

int main() {
	int x;
    cin >> x;
    while (x != 0) {
    	int v_pos = 1;     // valor posicional
        int x_impar = 0;   // transformación
        while (x > 0) {
            int d = x%10;
            if (d%2 == 0) ++d;
            x_impar = x_impar + d*v_pos;
            v_pos = v_pos*10;
            x = x/10;
        }
        cout << x_impar << endl;
        cin >> x;
    }
}