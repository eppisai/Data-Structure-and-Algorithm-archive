//graph coloring problem
#include<bits/stdc++.h>
using namespace std;

int V, m;

bool isSafe(vector<vector<int>> graph, int color[])
{
    for (int i = 0; i < V; i++)
        for (int j = i + 1; j < V; j++)
            if (graph[i][j] && color[j] == color[i])
                return false;
    return true;
}

void printSolution(int color[])
{
    cout << "\n Colors assigned are as follows \n";
    for (int i = 0; i < V; i++)
        cout << "\t"<< i << " vertex is given color " << color[i]<<endl;
    cout << "\n";
}

bool graphColoring(vector<vector<int>> &graph, int m, int i, int color[])
{
    if (i == V) {
        if (isSafe(graph, color)) {
            printSolution(color);
            return true;
        }
        return false;
    }

    for (int j = 1; j <= m; j++) {
        color[i] = j;
        if (graphColoring(graph, m, i + 1, color))
            return true;

        color[i] = 0;
    }
    return false;
}

int main()
{

    cout<<"\n Enter number of vertices : ";
    cin>>V;
    cout<<"\n Enter the number of colors : ";
    cin>>m;
    cout<<"\n Enter the Adjacency matrix : \n";
    vector<vector<int>> graph(V, vector<int> (V,0));
    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++)
            cin>>graph[i][j];
    }
    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = 0;

    if (!graphColoring(graph, m, 0, color))
        cout << "Solution does not exist!";

    return 0;
}
/*4
 3
0 1 1 1
1 0 1 0
1 1 0 1
1 0 1 0
*/


