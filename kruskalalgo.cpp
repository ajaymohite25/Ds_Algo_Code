#include <iostream>
using namespace std;
int I = INT16_MAX;
void unionn(int *disjset, int p1, int p2)
{
    if (disjset[p1] > disjset[p2])
    {
        disjset[p1] = disjset[p1] + disjset[p2];
        disjset[p2] = p1;
    }
    else
    {
        disjset[p2] = disjset[p1] + disjset[p2];
        disjset[p1] = p2;
    }
}
int findparent(int *disjset, int elemt)
{
    while (disjset[elemt] > 0)
    {
        elemt = disjset[elemt];
    }
    return elemt;
}
int main()
{
    int v, v1, min = I, v2, e, edg, c = 0;
    cout << "enter no. of vertices & edges" << endl;
    cin >> v >> e;
    int graph[3][e];
    int st[2][v - 1];
    int incld[e] = {0};
    int disjset[v + 1]; //+1 because 0 is not included
    for (int i = 1; i <= v; i++)
        disjset[i] = -1;
    cout << "i/p graph" << endl;
    for (int i = 0; i < e; i++)
    {
        cout << "enter vertices" << endl;
        cin >> v1 >> v2;
        graph[0][i] = v1;
        graph[1][i] = v2;
        cout << "enter value" << endl;
        cin >> graph[2][i];
    }

    while (c < v - 1)
    {   min=I;
        for (int i = 0; i < e; i++)//finding min edge
        {  
            if (incld[i] != 1 && min > graph[2][i])
            {
                min = graph[2][i];
                v1 = graph[0][i];
                v2 = graph[1][i];
                edg = i;
            }
        }
        if (findparent(disjset, v1) != findparent(disjset, v2))
        {
            unionn(disjset, findparent(disjset, v1), findparent(disjset, v2));
            st[0][c] = v1;
            st[1][c] = v2;
            c++;
        }
        incld[edg] = 1;
    }
    for (int i = 0; i < v - 1; i++)//diplaying spaning tree
    {
        cout << st[0][i];
        cout << st[1][i];
        cout << endl;
    }
}
