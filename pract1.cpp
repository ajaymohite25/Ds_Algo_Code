#include <iostream>
#include <vector>
#include <set>
using namespace std;
int t[1002][1002];

int main()
{
    // vector<int> visited;
    // vector<int> vis(3);
    // visited = vis;

    // cout << visited.size();

    set<int> d;
    d.insert(1);
    d.insert(2);
    d.insert(3);
    // cout << d.size();
    // d.clear();
    d.erase(d.find(1));
    for (auto x : d)
        cout << x << " ";

    // cout << d.size();
}