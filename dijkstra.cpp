//Dijkstra's algorithm (Graph theory)
#include <iostream>
#include <climits>
#define I INT_MAX;
using namespace std;
const int novert = 6;
int main()
{
    void dijkstras(int, int[novert + 1][novert + 1], int[]);
    int i = I;
    int distance[novert + 1];
    int graph[novert + 1][novert + 1] = {
        {i, i, i, i, i, i, i},
        {i, i, 2, 11, i, i, i},      
        {i, 2, i, 6, 7, 12, i},      
        {i, 11, 6, i, i, 5, i},
        {i, i, 7, i, i, 9, 14},
        {i, i, 12, 5, 9, i, 13},
        {i, i, i, i, 14, 13, i}
        }; //matrix m*m=ver+1*ver+1
    cout << "enter starting point" << endl;
    int startvertex;
    cin >> startvertex;
    dijkstras(startvertex, graph, distance);
    for (int b = 1; b <= novert; b++)
    {
        if (distance[b] == 2147483647)
            cout << "from " << startvertex << " can't go to " << b << endl;
        else
            cout << startvertex << " to " << b << " distance is:" << distance[b] << endl;
    }
}
void dijkstras(int s, int graph[novert + 1][novert + 1], int distance[novert + 1]) //function for finding min distances of all destinations(vertices) from source
{
    int i = I; 
    int visitedvertex[novert + 1] = {0};
    distance[s] = 0;
    visitedvertex[s] = 1;
    int v=s, min;//
=
    for (int h = 1; h <= novert; h++) //finding distance of all vertices from startvertex
    {
        if (visitedvertex[h] == 0)
        {
            distance[h] = graph[s][h];
        }
    }
    for (int j = 1; j < novert - 1; j++) //will repeat for (no. of vertex-2)times as we will not visit first and last vertex
    {
        min = I;
        for (int k = 1; k <=novert; k++)//finding vertex which has min distance from starvertex
        {
            if (visitedvertex[k] == 0 && distance[k] < min)
            {
                min = distance[k];
                v = k;
            }
        }
         path[gg++]=v;
        visitedvertex[v] = 1;
        for (int g = 1; g <= novert; g++) //performing relaxation on selected vertex (i.e updating distances of all vertices from startvertex by finding new possible paths)
        {
            if (visitedvertex[g] == 0 && graph[v][g] != i)
            {
                if (distance[g] > distance[v] + graph[v][g])
                {
                    distance[g] = graph[v][g] + distance[v];
                }
            }
        }
    }
  
}
/* 1.___7*7________vertices=6__________directed______________     
        {i, i, i, i, i, i, i},
        {i, i, 50, 45, 10, i, i},      
        {i, i, i, 10, 15, i, i},      
        {i, i, i, i, i, 30, i},
        {i, 10, i, i, i, 15, i},
        {i, i, 20, 35, i, i, i},
        {i, i, i, i, i, 3, i}
2.______9*9_________vertices=8________directed________________
        { i, i, i, i, i, i, i, i, i }, 
        { i, i, 1, 2, 5, i, i, i, i }, 
        { i, i, i, i, i, 4, 11, i, i }, 
        { i, i, i, i, i, 9, 5, 16, i }, 
        { i, i, i, i, i, i, i, 2, i }, 
        { i, i, i, i, i, i, i, i, 18 }, 
        { i, i, i, i, i, i, i, i, 13 }, 
        { i, i, i, i, i, i, i, i, 2 }, 
        { i, i, i, i, i, i, i, i, i }
3._______7*7________vertices=6________directed_________________
	    {i, i, i, i, i, i, i},
        {i, i, 2, 4, i, i, i},
        {i, i, i, 1, 7, i, i},
        {i, i, i, i, i, 3, i},
        {i, i, i, i, i, i, 1},
        {i, i, i, i, 2, i, 5},
        {i, i, i, i, i, i, i}
3.1.___non directed_______vertices=6___________________________________________
        {i, i, i, i, i, i, i},
        {i, i, 2, 4, i, i, i},
        {i, 2, i, 1, 7, i, i},
        {i, 4, 1, i, i, 3, i},
        {i, i, 7, i, i, 2, 1},
        {i, i, i, 3, 2, i, 5},
        {i, i, i, i, 1, 5, i}
4._________11*11__________vertices=10_____________________dircted_________

        { i, i, i, i, i, i, i, i, i,i,i }, 
        { i, i, 1, 2, 3, i, i, i, i ,i,i}, 
        { i, i, i, i, i, 5, i, 4, i,i,i }, 
        { i, i, 7, i, 8, i, 6, i, i ,i,i}, 
        { i, i, i, i, i, i, 9, i, i ,i,i}, 
        { i, i, i, 10, i, i, 12, 11, i,i,i}, 
        { i, i, i, i, i, i, i, i, 13 ,14,i}, 
        { i, i, i, i, i, i, i, i, 16 ,i,15}, 
        { i, i, i, i, i, 17, i, i, i ,i,18},
	    { i, i, i, i, 19, i, i, i, 21 ,i,20}, 
	    { i, i, i, i, i, i, i, i, i,i,i }
5.___7*7________vertices=6__________nondirected______________

 	    {i, i, i, i, i, i, i},
        {i, i, 2, 11, i, i, i},      
        {i, 2, i, 6, 7, 12, i},      
        {i, 11, 6, i, i, 5, i},
        {i, i, 7, i, i, 9, 14},
        {i, i, 12, 5, 9, i, 13},
        {i, i, i, i, 14, 13, i}
______________________________________________________________*/