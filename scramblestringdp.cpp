#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
unordered_map<string, bool> t;
bool isScramble(string s1, string s2)
{
    int n = s1.length();
    if (s1.length() != s2.length())
        return false;
    if (s1 == s2)
        return true;
    // if(n==0)
    // return false;
    if (t.find(s1 + s2) != t.end())
        return t[s1 + s2];
    for (int k = 1; k < n; k++)
    {
        bool lsub, rsub, slsub, srsub;

        if (t.find(s1.substr(0, k) + s2.substr(0, k)) == t.end())
            t[s1.substr(0, k) + s2.substr(0, k)] = lsub = isScramble(s1.substr(0, k), s2.substr(0, k));
        else
            lsub = t[s1.substr(0, k) + s2.substr(0, k)];

        if (t.find(s1.substr(k, n - k) + s2.substr(k, n - k)) == t.end())
            t[s1.substr(k, n - k) + s2.substr(k, n - k)] = rsub = isScramble(s1.substr(k, n - k), s2.substr(k, n - k));
        else
            rsub = t[s1.substr(k, n - k) + s2.substr(k, n - k)];

        if (t.find(s1.substr(0, k) + s2.substr(n - k, k)) == t.end())
            t[s1.substr(0, k) + s2.substr(n - k, k)] = slsub = isScramble(s1.substr(0, k), s2.substr(n - k, k));
        else
            slsub = t[s1.substr(0, k) + s2.substr(n - k, k)];

        if (t.find(s1.substr(k, n - k) + s2.substr(0, n - k)) == t.end())
            t[s1.substr(k, n - k) + s2.substr(0, n - k)] = srsub = isScramble(s1.substr(k, n - k), s2.substr(0, n - k));
        else
            srsub = t[s1.substr(k, n - k) + s2.substr(0, n - k)];

        if (lsub && rsub)
            return t[s1 + s2] = true;

        if (slsub && srsub)
            return t[s1 + s2] = true;
    }
    return t[s1 + s2] = false;
}
int main()
{
    string S1 = "phqtrnilf";
    string S2 = "ilthnqrpf";

    if (isScramble(S1, S2))
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }

    return 0;
}