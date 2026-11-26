#include <iostream>
#include <vector>
using namespace std;

// retorna |A ∩ B|.
// prec: A i B ordenats estrictament creixents.
int common(const vector<int>& A, const vector<int>& B)
{
    // implementació: una variant de fusió de dues seqüències ordenades
    int m = A.size();
    int n = B.size();
    int i = 0;
    int j = 0;
    int c = 0;
    while (i < m and j < n) {
        if (A[i] < B[j])
            ++i;
        else if (A[i] > B[j])
            ++j;
        else {
            ++i;
            ++j;
            ++c;
        }
    }
    return c;
}

// retorna J(A, B).
// prec: |A|+|B| ≥ 1 i A i B ordenats estrictament creixents.
double Jaccard_index(const vector<int>& A, const vector<int>& B)
{
    double c = common(A, B);
    return c / (A.size() + B.size() - c);
}

int main()
{
    cout.setf(ios::fixed);
    cout.precision(3);
    int m;
    while (cin >> m) {
        vector<int> A(m);
        for (int i = 0; i < m; ++i)
            cin >> A[i];
        int n;
        cin >> n;
        vector<int> B(n);
        for (int i = 0; i < n; ++i)
            cin >> B[i];
        cout << Jaccard_index(A, B) << endl;
    }
}
