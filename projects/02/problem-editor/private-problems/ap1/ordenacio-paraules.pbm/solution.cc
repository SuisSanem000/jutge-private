#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool es_minuscula(char c)
{
    return c >= 'a' and c <= 'z';
}

bool abans(const string& x, const string& y)
{
    bool bx = es_minuscula(x[0]);
    bool by = es_minuscula(y[0]);
    if (bx != by)
        return bx;
    int sx = x.size();
    int sy = y.size();
    if (sx != sy)
        return sx < sy;
    return x < y;
}

void ordenar(vector<string>& paraules)
{
    sort(paraules.begin(), paraules.end(), abans);
}
