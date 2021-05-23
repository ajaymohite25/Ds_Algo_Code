#include <iostream>
#include <unordered_map>
using namespace std;

bool find3Numbers(int a[], int n, int k)
{
    unordered_map<int, int> map;

    for (int i = 0; i < n; i++)
    {
        map.insert({a[i], i});
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (map[k - a[i] - a[j]] && map[k - a[i] - a[j]] != i && map[k - a[i] - a[j]] != j)
            {
                cout << a[i] << " " << a[j] << " " << k - a[i] - a[j];
                cout << endl;
                return true;
            }
        }
    }

    return false;
}
int main()
{
    int n = 50, k = 181;
    int a[n] = {589, 343, 609, 61, 222, 759, 955, 889, 147, 691, 950, 844, 431, 621, 749, 68, 537, 784, 36, 227, 186, 39, 854, 630, 225, 749, 924, 360, 258, 767, 945, 956, 319, 727, 412, 26, 356, 2, 550, 497, 585, 516, 965, 343, 76, 914, 143, 197, 949, 73};
    cout << find3Numbers(a, n, k);
    return 0;
}