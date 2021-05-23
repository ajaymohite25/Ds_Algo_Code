#include <iostream>
using namespace std;
int trappingWater(int a[], int n)
{

    int lmax = 0, rmax = 0;
    int amtwater = 0;
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (a[i] < a[j])
        {
            if (a[i] > lmax)
            {
                lmax = a[i];
            }
            else
            {
                amtwater = amtwater + lmax - a[i];
            }
            i++;
        }
        else
        {
            if (a[j] > rmax)
                rmax = a[j];
            else
            {
                amtwater = amtwater + rmax - a[j];
            }
            j--;
        }
    }
    return amtwater;
}

int main()
{
    int n = 3;
    int a[] = {2, 0, 2};
    cout << trappingWater(a, n);
    return 0;
}