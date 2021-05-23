#include <iostream>
using namespace std;
void rotate(int a[], int f, int l)
{
    int temp = a[l];
    int i;
    for (i = l; i > f; i--)
    {
        a[i] = a[i - 1];
    }
    a[i] = temp;
}
int findnxt(int a[], int k, int n, int pono)
{
    if (pono == -1)
    {
        for (int i = k + 1; i < n; i++)
        {
            if (a[i] < 0)
            {
                return i;
            }
        }
    }
    else
    {
        for (int i = k + 1; i < n; i++)
        {
            if (a[i] > 0)
            {
                return i;
            }
        }
    }
    return -1;
}

void alter(int a[], int n)
{
    int k = 1, i = 0;
    while (i < n)
    {
        if (a[i] >= 0 && a[i + 1] >= 0)
        {
            k = findnxt(a, k, n, -1);
            if (k > 0)
            {
                rotate(a, i + 1, k);
                i = i + 2;
            }
            else
            {
                break;
            }
        }
        else if (a[i] < 0 && a[i + 1] < 0)
        {
            k = findnxt(a, k, n, 1);
            if (k > 0)
            {
                rotate(a, i + 1, k);
                i = i + 2;
            }
            else
            {
                break;
            }
        }
        else
        {
            i++;
        }
    }
}
int main()
{
    int n = 10;
    int a[n] = {-5, 3, -4, -7, -1, -2, -8, -9, 1, -4};
    alter(a, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}
