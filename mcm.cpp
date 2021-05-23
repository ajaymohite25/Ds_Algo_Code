#include <iostream>
#include <cstring>
using namespace std;
int t[1002][1002];

int x(int arr[], int i, int j)
{
    if (i >= j)
        return 0;

    if (t[i][j] != -1)
        return t[i][j];

    int ans = INT16_MAX;

    for (int k = i; k < j; k++)
    {
        int temp = x(arr, i, k) + x(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];

        if (temp < ans)
            ans = temp;
    }

    return t[i][j] = ans;
}
int main()
{
    for (int i = 0; i < 1002; i++)
        for (int j = 0; j < 1002; j++)
            t[i][j] = -1;
    int N = 5;
    int arr[] = {40, 20, 30, 10, 30};

    cout << x(arr, 1, N - 1);
    return 0;
}