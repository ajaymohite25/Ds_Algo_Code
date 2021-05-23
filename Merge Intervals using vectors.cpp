#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace std::chrono;
vector<vector<int>> merge(vector<vector<int>> &interval)
{
    int i = 0, j = 1, f = 0;
    sort(interval.begin(), interval.end());
    vector<vector<int>> intervalans;

    while (j < interval.size())
    {
        if (interval[i][1] >= interval[j][0])
        {
            if (interval[i][1] < interval[j][1])
            {
                interval[i][1] = interval[j][1];
            }
            j++;
            f = 0;
        }
        else
        {
            intervalans.push_back({interval[i][0], interval[i][1]});

            i = j;
            j++;
            f = 1;
        }
    }

    if (f == 0)
    {
        intervalans.push_back({interval[i][0], interval[i][1]});
    }
    else if (j == interval.size())
    {
        intervalans.push_back({interval[i][0], interval[i][1]});
    }

    return intervalans;
}
int main()
{

    vector<vector<int>> interval = {{1, 4}, {2, 3}};

    auto start = high_resolution_clock::now();

    interval = merge(interval);

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<minutes>(stop - start);

    cout << "Time taken by function: "
         << duration.count() << " ms" << endl;
    for (int i = 0; i < interval.size(); i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << interval[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
//{1, 6}, {1, 5}, {2, 16}, {1, 10}, {18, 20}, {16, 18}, {21, 23}