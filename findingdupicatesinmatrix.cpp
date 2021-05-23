#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

int kthSmallest(int mat[4][5], int ro, int c)
{

    vector<int> r;
    unordered_map<int, int> mp;
    for (int i = 0; i < c; i++)
    {
        mp[mat[0][i]] = 0;
    }

    for (int i = 1; i < ro; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (mp.find(mat[i][j]) != mp.end())
            {
                if (mp[mat[i][j]] < i)
                {
                    mp[mat[i][j]] = mp[mat[i][j]] + 1;
                }
            }
        }
    }

    for (auto i : mp)
    {
        if (i.second == ro - 1)
            r.push_back(i.first);
    }
    for (auto i : r)
        cout << i << " ";
}

int main()
{
    int mat[4][5] = {
        {1, 2, 1, 4, 8},
        {7, 7, 7, 8, 1},
        {8, 7, 7, 3, 1},
        {8, 1, 2, 7, 9},
    };
    kthSmallest(mat, 4, 5);
    return 0;
}