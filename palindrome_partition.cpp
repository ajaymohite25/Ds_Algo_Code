#include <iostream>
#include <string>
using namespace std;
int t[501][501];
bool ispalindrome(string s, int i, int j)
{
    while (i < j)
    {
        if (s[i] == s[j])
        {
            i++, j--;
        }
        else
        {
            return false;
        }
    }
    return true;
}
int palindromicPartitio(string s, int i, int j)
{
    if (i >= j)
        return 0;

    if (t[i][j] != -1)
        return t[i][j];

    if (ispalindrome(s, i, j) == true)
        return 0;

    int ans = INT16_MAX;
    for (int k = i; k < j; k++)
    {
        int left, right;
        if (t[i][k] != -1)
        {
            left = t[i][k];
        }
        else
        {
            left = t[i][k] = palindromicPartitio(s, i, k);
        }
        if (t[k + 1][j] != -1)
        {
            right = t[k + 1][j];
        }
        else
        {
            right = t[k + 1][j] = palindromicPartitio(s, k + 1, j);
        }

        int temp = left + right + 1;

        if (ans > temp)
        {
            ans = temp;
        }
    }
    return t[i][j] = ans;
}
int palindromicPartition(string str)
{
    for (int i = 0; i < 501; i++)
        for (int j = 0; j < 501; j++)
            t[i][j] = -1;
    return palindromicPartitio(str, 0, str.length() - 1);
}

int main()
{
    string str = "ababbbabbababa";
    cout << palindromicPartition(str);
    return 0;
}