#include <iostream>
#include <string>
using namespace std;

int maxSubarraySum(int a[], int n)
{
    long long int sum = 0, consum;
    consum = INT64_MIN;
    for (int i = 0; i < n; i++)
    {
        sum = a[i] + sum;
        if (sum >= consum)
        {
            consum = sum;
        }
        if (sum < 0)
        {
            sum = 0;
        }
    }
    return consum;
}

int main()
{
    int n = 5;
    int a[n] = {1, 2, 3, -2, 5};
    int c = maxSubarraySum(a, n);
    cout << c << " sum";
}
