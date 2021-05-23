#include <iostream>
#include <string.h>
using namespace std;
int subset(string ip, string sub)
{

    static int count = 0;

    if (ip == "")
    {

        cout << sub << endl;

        count++;

        return count;
    }

    string op1 = sub;
    string op2 = sub;

    string k = '_' + ip.substr(0, 1);

    op1 = op1 + k;
    op2 = op2 + ip.substr(0, 1);
    ip.erase(ip.begin());

    subset(ip, op1); //not included

    subset(ip, op2); //included

    return count;
}
int main()
{

    string s = "aac";
    s.erase(s.begin());

    cout << subset(s, "a");
    return 0;
}