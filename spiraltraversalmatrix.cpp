#include <iostream>
#include <vector>
using namespace std;

vector<int> spirallyTraverse(vector<vector<int>> v, int ro, int co)
{
    int count = 0;
    int i = 0, r = ro - 1, c = co - 1, no = ro * co;
    int t, k, j, z;
    vector<int> g;
    while (count < no)
    {

        for (t = i; t <= c; t++)
        {

            count++;
            g.push_back(v[i][t]);
        }
        if (count < no)
        {
            for (k = i + 1; k <= r; k++)
            {

                count++;
                g.push_back(v[k][t - 1]);
            }
        }
        if (count < no)
        {
            for (j = t - 2; j >= i; j--)
            {

                count++;
                g.push_back(v[k - 1][j]);
            }
        }
        if (count < no)
        {
            for (z = k - 2; z >= i + 1; z--)
            {

                count++;
                g.push_back(v[z][j + 1]);
            }
        }
        i = i + 1, r = r - 1, c = c - 1;
    }
    return g;
}
int main()
{

    vector<vector<int>> a = {{6, 6, 2, 28, 2},
                             {12, 26, 3, 28, 7},
                             {22, 25, 3, 4, 23}};
    vector<int> v;
    v = spirallyTraverse(a, a.size(), a[0].size());

    for (int z = 0; z < v.size(); z++)
        cout << v[z] << " ";
}