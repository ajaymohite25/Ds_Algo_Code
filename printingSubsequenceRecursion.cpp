#include <iostream>
#include <algorithm>
using namespace std;

int t[50][50];
int lcs(int x, int y, string s1, string s2)
{

    if (x == 0 || y == 0)
        return 0;

    if (t[x][y] != -1)
        return t[x][y];
    if (s1[x - 1] == s2[y - 1])
    {

        return t[x][y] = 1 + lcs(x - 1, y - 1, s1, s2);
    }

    else
    {

        return t[x][y] = max(lcs(x - 1, y, s1, s2), lcs(x, y - 1, s1, s2));
    }
}
int main()
{
    for (int i = 0; i < 50; i++)
        for (int j = 0; j < 50; j++)
            t[i][j] = -1;
    int A = 6, B = 5;
    string str1 = "abcdaf"; //abacdb
    string str2 = "acbcf";  //abcdae
    cout << lcs(A, B, str1, str2) << endl;
    string ans;
    do
    {
        if (t[A][B] != -1)
        {
            if (str1[A - 1] == str2[B - 1])
            {
                ans.push_back(str1[A - 1]);
                A--, B--;
            }
            else
            {
                ans.push_back(str1[A - 1]);
                ans.push_back(str2[B - 1]); //for printeing super sequence
                A--, B--;
            }
        }
    } while (A != 0 && B != 0);

    reverse(ans.begin(), ans.end());
    cout << ans;

    cout << endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << t[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}