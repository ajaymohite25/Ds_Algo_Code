#include <iostream>
using namespace std;
void swap(int arr[], int e1, int e2)
{
    int temp;
    temp = arr[e1];
    arr[e1] = arr[e2];
    arr[e2] = temp;
}
int partition(int a[], int l, int h)
{
    int piv;
    piv = a[l];
    int i, j;
    i = l;
    j = h;
    do
    {
        do
        {
            i++;
        } while (a[i] <= piv);
        do
        {
            j--;
        } while (a[j] > piv);

        if (i < j)
            swap(a, i, j);

    } while (i < j);

    swap(a, l, j);

    return j;
}
void qs(int a[], int l, int h)
{
    int j;
    if (l < h)
    {
        j = partition(a, l, h);
        qs(a, l, j);
        qs(a, j + 1, h);
    }
}
int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int a[n + 1];
    a[n] = INT32_MAX; //infinnity
    cout << "Enter elements:" << endl;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    qs(a, 0, n);
    cout << "Array after Sorting: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}