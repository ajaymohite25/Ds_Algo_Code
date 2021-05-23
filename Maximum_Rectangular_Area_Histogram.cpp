#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int calculateSpan(vector<int> a, int n)
{

    int max = INT16_MIN;
    stack<int> s;
    vector<int> smal, smar, area;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            smal.push_back(-1);
        }
        else if (a[i] > a[s.top()])
        {
            smal.push_back(s.top());
        }
        else
        {
            while (!s.empty() && a[s.top()] >= a[i])
            {
                s.pop();
            }
            if (s.empty())
            {
                smal.push_back(-1);
            }
            else
            {
                smal.push_back(s.top());
            }
        }

        s.push(i);
    }

    while (!s.empty())
    {
        s.pop();
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (i == n - 1)
        {
            smar.push_back(n);
        }
        else if (a[i] > a[s.top()])
        {
            smar.push_back(s.top());
        }
        else
        {
            while (!s.empty() && a[i] <= a[s.top()])
            {
                s.pop();
            }
            if (s.empty())
            {
                smar.push_back(n);
            }
            else
            {
                smar.push_back(s.top());
            }
        }
        s.push(i);
    }

    reverse(smar.begin(), smar.end());

    for (int i = 0; i < n; i++)
    {
        area.push_back((smar[i] - smal[i] - 1) * a[i]); //to find area ((smar[i] - smal[i] - 1) * a[i])width*height
    }

    for (int i = 0; i < n; i++)
    {
        if (max < area[i])
            max = area[i];
    }

    return max;
}
int main()
{

    vector<int> a = {6, 2, 5, 4, 5, 1, 6};
    // int g = calculateSpan(a, a.size());
    cout << 365 % 7;
    // cout << g << " ";
    return 0;
}
