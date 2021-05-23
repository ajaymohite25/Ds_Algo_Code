#include <iostream>
using namespace std;
int maxpowerr(int n)
{
    int count = 0;
    while ((1 << count) <= n)
    {
        count++;
    }

    return count - 1;
}
int countSetBits(int n)
{
    if (n == 0)
        return 0;
    int maxpoweroftwo = maxpowerr(n);

    int maxpowbits = (maxpoweroftwo) * (1 << (maxpoweroftwo - 1)), msbreamining = n - (1 << maxpoweroftwo) + 1;

    int ans = maxpowbits + msbreamining + countSetBits(n - (1 << maxpoweroftwo));
    return ans;
}

int main()
{
    cout << countSetBits(20);

    return 0;
}