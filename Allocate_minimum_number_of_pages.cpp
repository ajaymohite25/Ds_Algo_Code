#include <iostream>
#include <algorithm>
using namespace std;

bool istrue(int a[], int n, int m, int max)
{

    int sum = 0, student = 1;
    for (int i = 0; i < n; i++)
    {
        sum = sum + a[i];
        if (sum > max)
        {
            student++;
            sum = a[i];
        }

        if (student > m)
            return false;
    }
    return true;
}

int findPages(int a[], int n, int m)
{
    int max = INT8_MIN, sum = 0, i, j;

    if (m > n)
        return -1;

    else
    {
        for (int i = 0; i < n; i++)
        {
            sum = sum + a[i];
            if (a[i] > max)
            {
                max = a[i];
            }
        }
        i = max, j = sum;
        while (i <= j)
        {
            int mid = i + (j - i) / 2;

            if (istrue(a, n, m, mid))
            {
                j = mid - 1;
            }

            else
            {
                i = mid + 1;
            }
        }
    }
    return i;
}
int main()
{
    int a[] = {12, 34, 67, 90};
    cout << findPages(a, 4, 2);
    // cout << max(a) << 1 - 7;
    return 0;
}