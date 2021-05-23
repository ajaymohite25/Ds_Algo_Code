#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int kthSmallest(int mat[4][4], int n, int k) //int mat[4][4], int n, int k
{
    int min = INT16_MAX, max = INT8_MIN;

    for (int i = 0; i < n; i++)
    {
        if (max < mat[i][n - 1])
        {
            max = mat[i][n - 1];
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (min > mat[i][0])
        {
            min = mat[i][0];
        }
    }

    int i = min, j = max;

    while (i < j)
    {
        int mid = (i + j) / 2;
        int count = 0;
        for (int h = 0; h < n; h++)
            count = count + upper_bound(mat[h], mat[h] + n, mid) - mat[h];

        if (count < k)
        {
            i = mid + 1;
        }
        else
        {
            j = mid;
        }
    }
    return j;
}

int main()
{
    int mat[4][4] = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {24, 29, 37, 48},
        {32, 33, 39, 50}};

    cout << kthSmallest(mat, 4, 1);
    return 0;
}