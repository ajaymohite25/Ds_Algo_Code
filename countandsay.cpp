#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
string saycount(string t)
{
    int i = 0, len = t.length();
    string temp = "";
    while (i < len)
    {
        int count = 1, k = i + 1;
        while (k < len && t[i] == t[k])
        {
            count++, k++;
        }
        temp += count + '0';
        temp += t[i];
        i = k;
    }

    return temp;
}
string countAndSay(int n)
{
    vector<string> countsayy;
    countsayy.push_back("1");
    countsayy.push_back("11");
    for (int i = 2; i < n; i++)
    {
        countsayy.push_back(saycount(countsayy[i - 1]));
    }
    return countsayy[n - 1];
}
int main()
{
    int x = 10;
    cout << countAndSay(x);
}