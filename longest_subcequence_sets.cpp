#include <iostream>
#include <unordered_set>

using namespace std;
int longestConsecutive(int a[], int n)
{
    int maxlen = INT16_MIN, c = 0;
    unordered_set<int> s;

    for (int i = 0; i < n; i++)
    {
        s.insert(a[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (s.find(a[i] - 1) == s.end())
        {
            int j = a[i];
            while (s.find(j) != s.end())
            {
                c++;
                j++;
            }
        }
        if (c > maxlen)
            maxlen = c;

        c = 0;
    }

    return maxlen;
}
int main()
{
    int n = 5;

    int a[n] = {1, 2, 3, 4, 5};

    cout << longestConsecutive(a, n);

    return 0;
}