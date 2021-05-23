#include <iostream>
#include <vector>
using namespace std;

vector<int> people;

void par(int n, int cur, int k)
{

    if (n == 1)
    {
        cout << people[0];
        return;
    }

    cur = (cur + k - 1) % n;

    people.erase(people.begin() + cur);

    par(n - 1, cur, k);
}
int main()
{

    int n = 500, k = 6;
    for (int i = 0; i < n; i++)
    {
        people.push_back(i + 1);
    }

    par(n, 0, k);

    return 0;
}