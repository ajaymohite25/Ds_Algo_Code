#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
vector<long long> nextsmallerElementl(vector<long long> a, int n)
{

    stack<long long> s;
    vector<long long> ans;
    for (long long i = n - 1; i >= 0; i--)
    {
        if (i == n - 1)
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
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    // vector<vector<int>> a = {{0, 1, 1, 1},
    //                          {0, 0, 1, 1},
    //                          {1, 1, 1, 1},
    //                          {0, 0, 0, 0}};
    // cout << rowWithMax1s(a, 4, 4);
    vector<long long> a = {6, 8, 0, 1, 3};
    vector<long long> g = nextsmallerElementl(a, a.size());
    for (int i : g)
        cout << i << " ";
    return 0;
}
