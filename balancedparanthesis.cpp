#include <iostream>
#include <vector>
using namespace std;

vector<string> bal;

void par(int o, int c, string op)
{

    if (o == 0 && c == 0)
    {

        bal.push_back(op);
        return;
    }
    string op1 = op;
    string op2 = op;

    if (o < c && o > 0)
    {
        op1.push_back('(');
        op2.push_back(')');
        par(o - 1, c, op1);
        par(o, c - 1, op2);
    }

    else if (o == c)
    {
        op.push_back('(');
        par(o - 1, c, op);
    }
    else
    {
        op.push_back(')');
        par(o, c - 1, op);
    }
}
int main()
{

    int n = 2;
    int o = ((n * 2) / 2) - 1;
    int c = (n * 2) / 2;
    par(o, c, "(");
    for (auto i : bal)
        cout << i << " ";
    return 0;
}