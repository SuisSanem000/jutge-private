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

// replace '(', ')' and ',' with ' ' in s
void remove_symbols(string& s)
{
    for (char& c : s) {
        if (c == '(' or c == ')' or c == ',') {
            c = ' ';
        }
    }
}

// returns the logic tree corresponding to the logic expression in tokens
LogicTree build(istringstream& tokens)
{
    string token;
    tokens >> token;
    if (token == "AND" or token == "OR") {
        LogicTree t1 = build(tokens);
        LogicTree t2 = build(tokens);
        int tag = token == "AND" ? AND : OR;
        return new Node { tag, t1, t2, "" };
    } else if (token == "NOT") {
        LogicTree t1 = build(tokens);
        return new Node { NOT, t1, nullptr, "" };
    } else {
        return new Node { LEAF, nullptr, nullptr, token };
    }
}

// returns the logic tree corresponding to the logic expression in expr
LogicTree build(string expr)
{
    remove_symbols(expr);
    istringstream tokens(expr);
    return build(tokens);
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

// destroys the nodes of a tree
void destroy(LogicTree t)
{
    if (t) {
        destroy(t->lft);
        destroy(t->rgt);
        delete t;
    }
}

// evaluates tree with true variables in trues
bool eval(LogicTree tree, const TrueVars& true_vars)
{
    if (tree->tag == LEAF) {
        return true_vars.count(tree->var);
    } else if (tree->tag == NOT) {
        return not eval(tree->lft, true_vars);
    } else if (tree->tag == AND) {
        return eval(tree->lft, true_vars) and eval(tree->rgt, true_vars);
    } else if (tree->tag == OR) {
        return eval(tree->lft, true_vars) or eval(tree->rgt, true_vars);
    } else {
        assert(false);
        return false;
    }
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

    // free memory
    destroy(tree);
}