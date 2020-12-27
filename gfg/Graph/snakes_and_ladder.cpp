#include <bits/stdc++.h>
using namespace std;
template <typename T>

class graph
{
public:
    map<T, list<T>> adj;
    //public:
    graph()
    {
        //map uses dynamic memory allocation , so no need to input number of edges.
    }
    void addEdge(T u, T v, bool bidir)
    {
        adj[u].push_back(v);
        if (bidir == true)
        {
            adj[v].push_back(u);
        }
    }
    int bfs(T src, T dest)
    {
        queue<T> q;
        map<T, int> distance; //To check which nodes are visited.
        map<T, T> parent;
        for (int i = 0; i < 42; i++)
        {
            distance[i] = INT_MAX;
        }

        q.push(src);
        distance[src] = 0;
        while (!q.empty())
        {

            T node = q.front();
            //cout<<node<<" ";
            q.pop();

            //      // now we have to put neighbours of the node into the queue and find their shortest distance

            for (auto neighbour : adj[node])
            {
                if (distance[neighbour] == INT_MAX)
                {
                    q.push(neighbour);
                    distance[neighbour] = distance[node] + 1;
                    parent[neighbour] = node;
                }
            }
        }
        // for(auto i:parent){
        //     cout<<i.first<<" "<<i.second<<endl;
        // }
        T temp = dest;
        while (temp != src)
        {
            cout << temp << " <-- ";
            temp = parent[temp];
        }
        cout << src << endl;
        return distance[dest];
    }
};
int main()
{
    graph<int> g;
    int board[50] = {0};
    board[2] = 13;
    board[5] = 2;
    board[9] = 18;
    board[18] = 11;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[25] = -10;
    board[32] = -2;
    board[34] = -22;

    //construct the graph by adding pair of edges

    for (int u = 0; u <= 35; u++)
    {
        // at every node you can throw dice
        for (int dice = 1; dice <= 6; dice++)
        {

            int v = u + dice + board[u + dice];
            g.addEdge(u, v, false);
        }
    }
    // for(auto i: g.adj){
    //     cout<<i.first<<"->";
    //     for(auto j:i.second){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }
    cout << "Shortest Distance is " << g.bfs(1, 36) << endl;
    return 0;
}