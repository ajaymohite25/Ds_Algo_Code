#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int median(vector<vector<int>> &a, int r, int c)
{
    int min = INT16_MAX, max = INT16_MIN;
    for (int i = 0; i < r; i++)
    {
        if (min > a[i][0])
        {
            min = a[i][0];
        }
        if (max < a[i][c - 1])
        {
            max = a[i][c - 1];
        }
    }

    int medianpos = (r * c + 1) / 2; //+1 is done ,as in array of 9(odd) elements 5th position element is middle element ,where we will find median

    while (min < max)
    {
        int mid = min + (max - min) / 2;
        int count = 0;
        for (int i = 0; i < r; i++)
        {
            count = count + upper_bound(a[i].begin(), a[i].end(), mid) - a[i].begin();
        }
        if (count < medianpos)
        {
            min = mid + 1; //median is in upper half
        }
        else
        {
            max = mid; //median is in lower half
        }
    }
    return max; //min is also ok
}
int main()
{
    vector<vector<int>> a = {{1, 3, 5},
                             {2, 6, 9},
                             {3, 6, 9}};
    cout << median(a, 3, 3);
    return 0;
}
