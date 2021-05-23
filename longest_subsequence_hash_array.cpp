#include <iostream>
#include <vector>
using namespace std;
int findLongestConseqSubseq(int a[], int n)
{
    int maxlen = INT16_MIN, c = 1, max = -1;

    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }

    vector<int> v(max + 1);

    for (int i = 0; i < n; i++)
    {
        v[a[i]] = 1;
    }
    for (int i = 0; i < max; i++)
    {
        if (v[i] == v[i + 1] && v[i] > 0 && v[i + 1] > 0) //v[i] > 0 && v[i + 1] > 0 for not considering 0's of hashs
        {
            c++;
        }
        else
        {
            if (c > maxlen)
            {
                maxlen = c;
            }
            c = 1;
        }
    }
    if (c > maxlen) //if [1,2,3,4,5]
        maxlen = c;
    return maxlen;
}
int main()
{
    int n = 5;

    int a[n] = {1, 2, 3, 4, 5};

    cout << findLongestConseqSubseq(a, n);

    return 0;
}