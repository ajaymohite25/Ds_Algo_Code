#include <iostream>
using namespace std;
int count = 0;
long long int t[1002][1002];

long long int knapsack(int wt[], int n, int sum)
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
        return t[n][sum] = (knapsack(wt, n - 1, sum) + knapsack(wt, n, sum - wt[n - 1]));
    }
    else
    {
        return t[n][sum] = knapsack(wt, n - 1, sum);
    }
}

int main()
{

    for (int i = 0; i < 1002; i++)
        for (int j = 0; j < 1002; j++)
            t[i][j] = -1;

    int weight[] = {1, 2, 5};
    int n = 3, sum = 11;
    cout << knapsack(weight, n, sum) << endl;

    return 0;
}