#include <iostream>
using namespace std;
int count=0;
int t[1001][1001];

bool knapsack(int wt[],int n ,int sum)
{

if(sum==0 || n==0)
{
    if(sum==0)
    return true;
    else return false;
}
if(t[n][sum]!=-1)
return t[n][sum];
if(wt[n-1]<=sum)
{
return t[n][sum]=(knapsack(wt,n-1,sum-wt[n-1])|| knapsack(wt,n-1,sum));
}
else
{
return t[n][sum]=knapsack(wt,n-1,sum);
}

}

int main()
{
    
    for (int i = 0; i <1001 ; i++)
        for (int j = 0; j < 1001; j++)
            t[i][j] = -1;
  
    int weight[] = {3, 34, 4, 12, 5, 2};
    int n = 6, sum = 30;
    cout << knapsack( weight, n,sum)<<endl;
  
return 0;
}