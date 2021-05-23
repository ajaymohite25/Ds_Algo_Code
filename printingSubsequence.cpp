#include <iostream>
#include <vector>
using namespace std;

int t[4][4];
int lcs(int x, int y, string s1, string s2)
{

    for (int i = 1; i <= x; i++)
    {
        for (int j = 1; j <= y; j++)
        {
            if (s1[i - 1] = s2[j - 1])
            {

                t[i][j] = 1 + t[i - 1][j - 1];
            }
            else
            {
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }
    }

    return t[x][y];
}

int main()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (i == 0 || j == 0)
                t[i][j] = 0;
        }
    }

    int A = 3, B = 3;
    string str1 = "abc";
    string str2 = "abc";
    vector<char> c;

    lcs(A, B, str1, str2);
    do
    {
        if (str1[A - 1] == str2[B - 1])
        {
            c.push_back(str1[A - 1]);
            A--, B--;
        }
        else
        {
            if (t[A - 1][B] >= t[A - 1][B])
            {
                A = A - 1, B = B;
            }
            else
            {
                A = A, B = B - 1;
            }
        }
    } while (A != 0 && B != 0);
    for (auto i : c)
        cout << i << " ";
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