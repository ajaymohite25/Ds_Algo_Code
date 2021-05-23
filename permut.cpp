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

if(ip[0]>='a' && ip[0]<='z' || ip[0]>='A' && ip[0]<='Z')
{
    op1.push_back(char(toupper(ip[0])));
    op2.push_back(char(tolower(ip[0])));
     ip.erase(ip.begin());
     subset(ip, op1); 
     subset(ip, op2);
     count++;
}
   
else
{
count++;
    op1.push_back(ip[0]);
    ip.erase(ip.begin());
    subset(ip, op1);
}
   
    return count;
}
int main()
{

    string s = "12a";
   cout << subset(s, "");
    return 0;
}