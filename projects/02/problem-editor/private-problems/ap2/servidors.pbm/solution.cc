#include <iostream>
#include <map>
#include <queue>
using namespace std;

using Jobs_Queue = priority_queue<int>;
using Servers = map<string, Jobs_Queue>;

void write_top(const Jobs_Queue& pq)
{
    if (pq.empty())
        cout << "-";
    else
        cout << pq.top();
}

Servers read_servers(int p)
{
    Servers servidors;
    for (int i = 0; i < p; ++i) {
        string id;
        cin >> id;
        servidors[id]; // = priority_queue<int>();
    }
    return servidors;
}

void add_job(Servers& servers)
{
    string id;
    int priority;
    cin >> id >> priority;
    auto it = servers.find(id);
    if (it == servers.end())
        cout << "identificador incorrecte" << endl;
    else {
        it->second.push(priority);
        write_top(it->second);
        cout << endl;
    }
}

void execute_job(Servers& servers, int& max_p)
{
    string id;
    int p;
    cin >> id >> p;
    auto it = servers.find(id);
    if (it == servers.end())
        cout << "identificador incorrecte" << endl;
    else {
        while (p > 0 and not it->second.empty()) {
            if (max_p < it->second.top())
                max_p = it->second.top();
            it->second.pop();
            --p;
        }
        write_top(it->second);
        cout << endl;
    }
}

void transfer_job(Servers& servers)
{
    string from, to;
    cin >> from >> to;
    auto from_it = servers.find(from);
    auto to_it = servers.find(to);
    if (from_it == servers.end() or to_it == servers.end()) {
        cout << "identificador incorrecte" << endl;
    } else {
        if (from_it->first != to_it->first and not from_it->second.empty()) {
            int priority = from_it->second.top();
            from_it->second.pop();
            to_it->second.push(priority);
        }
        write_top(from_it->second);
        cout << " ";
        write_top(to_it->second);
        cout << endl;
    }
}

int main()
{
    int p;
    cin >> p;
    Servers servers = read_servers(p);

    int max_p = -1;
    string query;
    while (cin >> query) {
        if (query == "ADD")
            add_job(servers);
        else if (query == "EXECUTE")
            execute_job(servers, max_p);
        else
            transfer_job(servers); // query == "TRANSFER"
    }

    cout << endl
         << "MAX VALUE: " << max_p << endl;
    cout << endl
         << "PENDING:" << endl;
    for (auto& elem : servers) {
        cout << elem.first << ": ";
        write_top(elem.second);
        cout << endl;
    }
}