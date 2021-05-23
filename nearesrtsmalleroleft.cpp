#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
vector<long long> nextLargerElementl(vector<long long> a, int n)
{

    stack<long long> s;
    vector<long long> ans;
    for (long long i = 0; i < n; i++)
    {
        if (i == 0)
        {
            ans.push_back(-1);
        }
        else if (a[i] > s.top())
        {
            ans.push_back(s.top());
        }
        else
        {
            while (!s.empty() && a[i] <= s.top())
            {
                s.pop();
            }
            if (s.empty())
                ans.push_back(-1);
            else
                ans.push_back(s.top());
        }

        s.push(a[i]);
    }
    // reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    // vector<vector<int>> a = {{0, 1, 1, 1},
    //                          {0, 0, 1, 1},
    //                          {1, 1, 1, 1},
    //                          {0, 0, 0, 0}};
    // cout << rowWithMax1s(a, 4, 4);
    vector<long long> a = {1, 3, 2, 4};
    vector<long long> g = nextLargerElementl(a, a.size());
    for (int i : g)
        cout << i << " ";
    return 0;
}
