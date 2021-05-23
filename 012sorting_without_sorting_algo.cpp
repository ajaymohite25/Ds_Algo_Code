#include <iostream>
#include <string>
using namespace std;
void swap(int i, int j, int a[])
{
	int temp;
	temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}
void sort012(int a[], int n)
{
	int low, mid;
	low = mid = 0;
	int high = n - 1;
	while (mid <= high)
	{
		switch (a[mid])
		{
		case 0:
		{
			swap(mid, low, a);
			low++, mid++;
			break;
		}
		case 1:
		{

			mid++;
			break;
		}
		case 2:
		{
			swap(mid, high, a);
			high--;
			break;
		}
		default:
		{
			cout << "array is wrong" << endl;
			return;
		}
		}
	}
}
int main()
{
	int n = 12;
	int a[n] = {2, 0, 1, 2, 0, 0, 1, 1, 0, 1, 2, 1};
	sort012(a, n);
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "-";
	}
}
// 0<--->(l-1)----->0
// l<--->(mid-1)--->1
// mid<->(h-1)----->unknown
// h<--->(n-1)----->2