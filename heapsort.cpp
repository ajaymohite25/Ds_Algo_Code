#include <iostream>
using namespace std;
void swap(int arr[], int e1, int e2)
{
    int temp;
    temp = arr[e1];
    arr[e1] = arr[e2];
    arr[e2] = temp;

}
void heapcreate(int a[], int i)
{
    int p = i / 2;
    while (p >= 1)
    {
        if (a[p] < a[i])
        {
            swap(a, p, i);
            i = p;
            p = p / 2;
        }
        else
            break;
    }
}
void del(int a[], int len)
{
    int x, lch, rch;
    while (len > 1)
    {
        x = 1, lch = 2 * x, rch = (2 * x) + 1;
        swap(a, x, len);
        len = len - 1;
        while (lch < len)
        {
            if (a[lch] >= a[rch] && a[x] <= a[lch])
            {
                swap(a, x, lch);
                x = lch;
                lch = 2 * x;
                rch = (2 * x) + 1;
            }
            else if (a[lch] < a[rch] && a[x] <= a[rch])
            {
                swap(a, x, rch);
                x = rch;
                lch = 2 * x;
                rch = (2 * x) + 1;
            }
            else
                break;
        }
    }
    
}
int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int a[n + 1];
    cout << "Enter elements:" << endl;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 2; i <= n; i++)
    {
        heapcreate(a, i);
    }
    cout << "Array after Sorting: ";
    del(a, n);
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}