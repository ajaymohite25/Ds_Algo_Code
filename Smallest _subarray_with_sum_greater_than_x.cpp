#include <iostream>
#include <vector>
using namespace std;
auto subArraySum(int a[], int n, int key)
{

    int start = 0, sum = 0, i = 0, minlen = n + 1;
    while (i < n)
    {

        while (sum <= key && i < n)
        {
            sum = sum + a[i];
            i++;
        }

        while (sum > key && start < n)
        {
            if (i - start < minlen)
            {
                minlen = i - start;
            }

            sum = sum - a[start];
            start++;
        }
    }

    return minlen;
}
int main()
{
    int a[] = {1, 4, 45, 6, 10, 19};
    int n = sizeof(a) / sizeof(a[0]);
    int sum = 51;

    int subar = subArraySum(a, n, sum);

    cout << subar;

    return 0;
}