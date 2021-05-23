#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#define MAX 1000
using namespace std;
vector<int> nsr(int H[], int n)
{
    stack<int> stacck;
    vector<int> nsmr;
    for (int i = n - 1; i >= 0; i--)
    {
        if (i == n - 1)
        {
            nsmr.push_back(n);
        }
        else if (H[i] > H[stacck.top()])
        {
            nsmr.push_back(stacck.top());
        }
        else
        {
            while (!stacck.empty() && H[i] <= H[stacck.top()])
            {
                stacck.pop();
            }

            if (stacck.empty())
                nsmr.push_back(n);
            else
            {
                nsmr.push_back(stacck.top());
            }
        }
        stacck.push(i);
    }
    reverse(nsmr.begin(), nsmr.end());
    // for (int k : nsmr)
    //     cout << k << " ";
    // cout << endl;
    return nsmr;
}
vector<int> nsl(int H[], int n)
{
    stack<int> stacck;
    vector<int> nsml;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            nsml.push_back(-1);
        }
        else if (H[i] > H[stacck.top()])
        {
            nsml.push_back(stacck.top());
        }
        else
        {
            while (!stacck.empty() && H[i] <= H[stacck.top()])
            {
                stacck.pop();
            }
            if (stacck.empty())
                nsml.push_back(-1);
            else
            {
                nsml.push_back(stacck.top());
            }
        }

        stacck.push(i);
    }
    // for (int k : nsml)
    //     cout << k << " ";
    // cout << endl;
    return nsml;
}
int mah(int H[], int n)
{
    vector<int> area, nsmr, nsml;
    int max = INT16_MIN;
    nsmr = nsr(H, n);
    nsml = nsl(H, n);
    for (int i = 0; i < n; i++)
    {
        area.push_back((nsmr[i] - nsml[i] - 1) * H[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (max < area[i])
            max = area[i];
    }

    return max;
}
int maxArea(int binarymat[4][4], int n, int m)
{
    vector<int> area;
    int histo[m] = {0};
    int max = INT16_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (binarymat[i][j] == 0)
                histo[j] = 0;
            else
            {
                histo[j] = histo[j] + binarymat[i][j];
            }
        }

        area.push_back(mah(histo, m));
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
    int n = 4, m = 4;
    int M[4][4] = {{0, 1, 1, 0},
                   {1, 1, 1, 1},
                   {1, 1, 1, 1},
                   {1, 1, 0, 0}};

    cout << maxArea(M, n, m);

    return 0;
}
