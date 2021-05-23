#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
vector<int> calculateSpan(vector<int> a, int n)
{

    stack<int> s;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            ans.push_back(1);
        }
        else if (a[i] < a[s.top()])
        {
            ans.push_back(i - s.top());
        }
        else
        {
            while (!s.empty() && a[i] >= a[s.top()])
            {
                s.pop();
            }
            if (s.empty())
                ans.push_back(i + 1);
            else
                ans.push_back(i - s.top());
        }

        s.push(i);
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
    vector<int> a = {100, 80, 60, 70, 60, 75, 85};
    vector<int> g = calculateSpan(a, a.size());
    for (int i : g)
        cout << i << " ";
    return 0;
}
