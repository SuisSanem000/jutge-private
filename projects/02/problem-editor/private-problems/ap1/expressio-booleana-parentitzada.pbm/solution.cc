#include <iostream>
using namespace std;

bool eval()
{
    char c;
    cin >> c;
    if (c == '(') {
        bool b1 = eval();
        char op;
        cin >> op;
        bool b2 = eval();
        cin >> c; /* c == ')' */
        if (op == '*') {
            return b1 and b2;
        } else /* op == '+' */ {
            return b1 or b2;
        }
    } else if (c == '0') {
        return false;
    } else if (c == '1') {
        return true;
    } else /* c == '!' */ {
        return not eval();
    }
}

int main()
{
    cout << eval() << endl;
}
