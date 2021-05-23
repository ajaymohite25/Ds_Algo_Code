#include <iostream>
#include <stack>
using namespace std;
void in(stack<int> &s, int temp)
{
    if (s.size() == 0)
    {
        s.push(temp);
        return;
    }
    int x = s.top();
    s.pop();
    in(s, temp);
    s.push(x);
}
void sub(stack<int> &s)
{

    if (s.size() == 0)
    {
        return;
    }
    int temp = s.top();
    s.pop();
    sub(s);
    in(s, temp);
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    sub(s);
    for (int i = 0; !s.empty(); i++)
    {
        cout << s.top() << endl;
        s.pop();
    }
}