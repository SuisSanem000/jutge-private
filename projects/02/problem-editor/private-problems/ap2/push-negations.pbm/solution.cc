#include <cassert>
#include <cctype>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
using namespace std;

class Formula {

    /** Nodes for the trees that represent formulas. */
    struct Node {
        char op; // operand ('a'-'z') or operator ('+' or '*')
        bool neg; // tells if this node is negated
        Node* left; // left subformula
        Node* right; // right subformula

        ~Node()
        {
            delete left;
            delete right;
        }
    };

    /** Pointer to the formula */
    Node* root;

    static Node* build_tree(const string& expr, int& cursor)
    {
        char c = expr[cursor++];
        if (c == '(') {
            Node* left = build_tree(expr, cursor);
            char op = expr[cursor++];
            Node* right = build_tree(expr, cursor);
            assert(expr[cursor] == ')');
            cursor++;
            return new Node { op, false, left, right };
        } else if (isalpha(c)) {
            return new Node { c, false, nullptr, nullptr };
        } else {
            assert(c == '!');
            Node* p = build_tree(expr, cursor);
            p->neg = not p->neg;
            return p;
        }
    }

    static void to_oss(Node* p, ostringstream& oss)
    {
        if (p->neg) {
            oss << '!';
        }
        if (isalpha(p->op)) {
            oss << p->op;
        } else {
            oss << '(';
            to_oss(p->left, oss);
            oss << p->op;
            to_oss(p->right, oss);
            oss << ')';
        }
    }

    static void push_negations_rec(Node* p)
    {
        if (not isalpha(p->op)) {
            if (p->neg) {
                p->neg = false;
                p->op = p->op == '+' ? '*' : '+';
                p->left->neg = not p->left->neg;
                p->right->neg = not p->right->neg;
            }
            push_negations_rec(p->left);
            push_negations_rec(p->right);
        }
    }

public:
    /** Builds the formula from an expression in a well formed string. */
    Formula(const string& expr)
    {
        int cursor = 0;
        root = build_tree(expr, cursor);
        assert(cursor == expr.size());
    }

    /** Destructor. */
    ~Formula()
    {
        delete root;
    }

    /** Converts the formula to an expression in a string. */
    string to_string() const
    {
        ostringstream oss;
        to_oss(root, oss);
        return oss.str();
    }

    /** Pushes all negations to the leaves. */
    void push_negations()
    {
        push_negations_rec(root);
    }
};

int main()
{
    string expr;
    while (cin >> expr) {
        Formula f(expr);
        f.push_negations();
        cout << f.to_string() << endl;
    }
}
