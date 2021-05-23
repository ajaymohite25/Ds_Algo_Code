#include <iostream>
#include <cstring>
using namespace std;
int t[1002][1002];
int count = 0;
int knapSack(int W, int wt[], int val[], int n)
{
    count++;
    if (n == 0 || W == 0)
        return 0;

    if (t[W][n] != -1)
        return t[W][n];

    if (wt[n - 1] <= W)
    {
        return t[W][n] = max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1), knapSack(W, wt, val, n - 1));
    }
    else
    {
        return t[W][n] = knapSack(W, wt, val, n - 1);
    }
}

int main()
{
    for (int i = 0; i < 1002; i++)
        for (int j = 0; j < 1002; j++)
            t[i][j] = -1;
    int values[] = {1, 2, 1};
    int weight[] = {4, 5, 9};
    int n = 3, w = 9;
    cout << knapSack(w, weight, values, n) << endl;
    cout << count << endl;
    cout << count << endl;
    return 0;
}