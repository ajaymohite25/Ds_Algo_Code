#include <iostream>
#include <vector>
using namespace std;
void swap(vector<int> &arr, int e1, int e2)
{
    int temp;
    temp = arr[e1];
    arr[e1] = arr[e2];
    arr[e2] = temp;
}
void threeWayPartition(vector<int> &x, int a, int b)
{
    int n = x.size();
    int i = 0, end = n - 1, start = 0;

    while (i <= end)
    {
        if (x[i] < a) //(x[i] <= 1) for three types of elements in array i.e(1,2,3)
        {
            swap(x, i, start);
            i++, start++;
        }
        else if (x[i] > b) // (x[i] > 2)
        {
            swap(x, i, end);
            end--;
        }
        else
        {
            i++;
        }
    }
}
int main()
{
    int a = 3, b = 6;
    vector<int> arr = {1, 2, 7, 2, 8, 5, 6, 4, 9};
    threeWayPartition(arr, a, b);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}