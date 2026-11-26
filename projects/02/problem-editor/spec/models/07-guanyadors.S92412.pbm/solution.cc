#include <string>
#include <vector>
using namespace std;

struct Player {
    string name;
    int score;
};

vector<string> winners(vector<Player>::iterator begin, vector<Player>::iterator end) {
    if (begin == end) {
        return {};
    }

    vector<string> result = {begin->name};
    int mx = begin->score;
    for (auto it = begin + 1; it != end; it++) {
        if (it->score > mx) {
            mx = it->score;
            result = {it->name};
        } else if (it->score == mx) {
            result.push_back(it->name);
        }
    }

    return result;
}
