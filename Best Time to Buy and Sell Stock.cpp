#include <iostream>
using namespace std;

int maxProfit(int a[], int m)
{

    int maxPro = 0;

    int min = INT16_MAX;

    for (int i = 0; i < m; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
        }
        else if (a[i] - min > maxPro)
        {
            maxPro = a[i] - min;
        }
    }

    return maxPro;
}

int main()
{
    int n = 4;
    int a[n] = {7, 2, 1, 4};
    cout << maxProfit(a, n);
    return 0;
}