#include <iostream>
#include <cstring>
using namespace std;
int t[1002][1002];
int count = 0;
int knapSack(int W, int wt[], int n)
{
    count++;
    if (n == 0 || W == 0 || n == 1)
    {
        if (n == 0)
            return INT32_MAX - 1;

        else if (W == 0)
            return 0;

        else
        {
            if (W % wt[0] == 0)
                return W / wt[0];
            else
                return INT32_MAX - 1;
        }
    }
    if (t[n][W] != -1)
        return t[n][W];

    if (wt[n - 1] <= W)
    {
        return t[W][n] = min(1 + knapSack(W - wt[n - 1], wt, n), knapSack(W, wt, n - 1));
    }
    else
    {
        return t[W][n] = knapSack(W, wt, n - 1);
    }
}

int main()
{
    for (int i = 0; i < 1002; i++)
        for (int j = 0; j < 1002; j++)
            t[i][j] = -1;

    int weight[] = {1};
    int n = 1, w = 2;
    cout << knapSack(w, weight, n) << endl;
    cout << count;
    return 0;
}