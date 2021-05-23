#include <iostream>
#include <unordered_set>
using namespace std;
bool subArrayExists(int a[], int n, int k)
{
    unordered_set<int> st;
    st.insert(k);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + a[i];
        if (st.find(sum) == st.end())
            st.insert(sum - k);
        else
            return true;
    }
    return false;
}
int main()
{
    int a[5] = {2, 3, 4, -2, 1};
    int k = 2; //what sum of sub array u want
    cout << subArrayExists(a, 5, k);
    return 0;
}