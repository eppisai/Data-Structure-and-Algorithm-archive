//kruskal Algorithm 
#include<bits/stdc++.h>
using namespace std;

class path
{
public:
    int v1, v2, wt;
    path(int a, int b, int w)
    {
        v1 = a; v2 = b; wt = w;
    }
};

bool operator< (path p1, path p2){
    return p1.wt > p2.wt;
}

class Minimum_Spanning_Tree
{
public:
    int parent[100];
    int v, e;
    priority_queue<path> p;
    priority_queue<path> q;

    Minimum_Spanning_Tree()
    {
        for(int i = 0; i < 99; i++){
            parent[i] = -1;
        }
    }

    void input();
    void kruskal();
    void display();

    int find_(int x)
    {
        if(parent[x] == -1)
            return x;
        return find_(parent[x]);
    }

    void union_(int x, int y)
    {
        parent[x] = y;
    }
};

void Minimum_Spanning_Tree::input()
{
    int v1, v2, w;
    cout<<"\n Enter number of vertex --> ";
    cin>>v;
    cout<<" Enter the number of edges --> ";
    cin>>e;
    cout<<endl;
    cout<<"\t Enter 1st, 2nd vertex and weight of each edge : ";
    for(int i = 0; i < e; i++)
    {
        cin>>v1>>v2>>w;
        path p1(v1, v2, w);
        p.push(p1); 
    }
}

void Minimum_Spanning_Tree::display()
{
    cout<<"\n Minimum Spanning Tree Edges are --> "<<endl;
    while(!q.empty())
    {
        path p1 = q.top();
        cout<<"\t"<<p1.v1<<" "<<p1.v2<<" "<<p1.wt<<endl;
        q.pop();
    }
}

void Minimum_Spanning_Tree::kruskal()
{
    int cnt = 0;
    while(cnt <= v-1)
    {
        path p1 = p.top();
        int a = find_(p1.v1); 
        int b = find_(p1.v2);
        if(a != b)
        {
            union_(a, b);
            q.push(p1);
            cnt++;
        }
        p.pop();
        if(cnt == v-1)
            break;

        if(cnt < v-1 && p.empty())
        {
            cout<<"\n Not a Connected Graph!!";
            exit(0);
        }
    }
}

int main()
{
    Minimum_Spanning_Tree mst;
    mst.input();
    mst.kruskal();
    mst.display();
    return 0;
}
/* 6 7
0 1 5
0 2 10
0 3 100
1 3 50
1 4 200
3 4 250
4 5 50
*/

