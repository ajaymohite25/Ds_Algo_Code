#include <iostream>
#include <unordered_map>
using namespace std;
int subset(string ip, string sub)
{

    static int count = 0;
    static unordered_map<string, int> map;
    if (ip == "")
    {
        if (sub == "")
            cout << "_" << endl;
        else
        {
            if (map[sub] != 1)
                cout << sub << endl;
        }

        count++;
        map[sub] = 1;
        return count;
    }

    string op1 = sub;
    string op2 = sub;

    op2.push_back(ip[0]);

    ip.erase(ip.begin());

    subset(ip, op1); //not included

    subset(ip, op2); //included
    return count;
}
int main()
{

    string s = "abc";
    cout << subset(s, "");
    return 0;
}