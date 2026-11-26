#include <cassert>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

// type for the set of variables which are true
using TrueVars = set<string>;

// tags for nodes in the tree
const int LEAF = 0;
const int NOT = 1;
const int AND = 2;
const int OR = 3;

// forward declaration
struct Node;

// logic trees are implemented with pointers to nodes
using LogicTree = Node*;

// nodes contain different informations according to their tag
struct Node {
    int tag; // can be LEAF, AND, OR, NOT
    LogicTree lft; // when AND, OR, NOT
    LogicTree rgt; // when AND, OR
    string var; // when LEAF
};

// returns the logic tree corresponding to the logic expression in words
LogicTree build2(istringstream& words)
{
    /* ··· */
}

// returns the logic tree corresponding to the logic expression in expr
LogicTree build(string expr)
{
    /* ··· */
}

// writes a logic tree with some indentation
void write(LogicTree tree, string indent = "")
{
    cout << indent;
    if (tree->tag == LEAF) {
        cout << tree->var << endl;
    } else if (tree->tag == NOT) {
        cout << "NOT" << endl;
        write(tree->lft, indent + " ");
    } else {
        cout << (tree->tag == AND ? "AND" : "OR") << endl;
        write(tree->lft, indent + " ");
        write(tree->rgt, indent + " ");
    }
}

// evaluates tree with true variables in true_vars
bool eval(LogicTree tree, const TrueVars& true_vars)
{
    /* ··· */
}

int main()
{
    // read an expression and build its tree
    string expr;
    cin >> expr;
    LogicTree tree = build(expr);

    // write the tree
    write(tree);
    cout << "----------" << endl;

    // read assignments and write their evaluation
    string line;
    getline(cin, line); // skip end of previous line
    while (getline(cin, line)) {
        TrueVars true_vars;
        istringstream iss(line);
        string var;
        while (iss >> var) {
            true_vars.insert(var);
        }
        if (eval(tree, true_vars)) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }
    }

    /* ... */
}