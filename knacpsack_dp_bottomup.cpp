#include <iostream>
using namespace std;
int count=0;

int knapsack(int wt[],int pr[],int n ,int c)
{int t[n+1][c+1];
    for(int i=0;i<n+1;i++)
    {t[i][0]=0;    
    }
for(int i=0;i<c+1;i++)
{
    t[0][i]=0;
}

for(int i=1;i<n+1;i++)
{

    for(int j=1;j<c+1;j++)
    {
        count++;
        if(wt[i-1]<=j)
        {
            t[i][j]=max(pr[i-1]+t[i-1][j-wt[i-1]],t[i-1][j]);
        }
        else
        {
            t[i][j]=t[i-1][j];
        }
    }
}

return t[n][c];

}

int main()
{
    int values[] = {1, 2, 3};
    int weight[] = {4, 5, 1};
    int n = 3, w = 9;
    cout << knapsack( weight, values, n,w)<<endl;
    cout<<count;
return 0;
}