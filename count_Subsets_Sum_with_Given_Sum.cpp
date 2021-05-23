#include <iostream>
using namespace std;
int count = 0;
int t[7][7];

int knapsack(int wt[], int n, int sum)
{

    if (sum == 0 || n == 0)
    {
        if (sum == 0)
        {
            return 1;
        }

        else
            return 0;
    }
    if (t[n][sum] != -1)
        return t[n][sum];
    if (wt[n - 1] <= sum)
    {
        return t[n][sum] = (knapsack(wt, n-1 , sum - wt[n - 1]) + knapsack(wt, n-1 , sum));
    }
    else
    {
        return t[n][sum] = knapsack(wt, n - 1, sum);
    }
}

int main()
{

    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 7; j++)
            t[i][j] = -1;

    int weight[] = {0, 0, 0, 0, 1};
    int n = 5, sum = 1;
    cout << knapsack(weight, n, sum) << endl;

    return 0;
}