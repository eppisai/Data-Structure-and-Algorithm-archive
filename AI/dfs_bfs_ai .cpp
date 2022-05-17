#include<bits/stdc++.h>

using namespace std;

class tree
{
    int levels, n;
    unordered_map<int, vector<int>> adj;
public:
    int root;
    tree()
    {
        int x;
        cout<<"\n Enter the number of levels of Tree --> ";
        cin>>levels;
        cout<<" Enter the max number of children for a node --> ";
        cin>>n;
        cout<<" Enter the root node --> ";
        cin>>root;
        queue<int> q;
        q.push(root);
        while(!q.empty())
        {
            int y = q.front(), cnt;
            q.pop();
            cout<<" Enter the number of children for "<<y<<" : ";
            cin>>cnt;
            if(cnt != 0)
                cout<<" Enter the values of children : ";
            while(cnt--)
            {
                cin>>x;
                q.push(x);
                adj[y].push_back(x);
            }
        }
        cout<<"\n <-- The tree is --> \n";
        display();
    }
    void display(){
        queue<int> q;
        q.push(root); q.push(-1);
        int l=1;
        cout<<" Level "<<l<<" \t ";
        while(!q.empty())
        {
            int t = q.front();
            q.pop();
            if(t == -1)
            {cout<<endl;
             l++;
             cout<<" Level "<<l<<" \t ";
            continue;}
            cout<<t<<" ";
            if(adj[t].size() == 0)
                continue;
            for(auto i:adj[t] ){
                q.push(i);
            }
            q.push(-1);
        }
    }
    void depth_first(int, int, bool&);
    void breadth_first(int, queue<int>&, bool&);
};

void tree::breadth_first(int to_search, queue<int> &q, bool &flag)
{
    if(q.empty() || flag)
        return;

    int v = q.front();
    q.pop();
    cout<<"\n "<<v<<" Vs "<<to_search<<" --> ";
    if(v == to_search)
    {
        flag = true;
        cout<<" True";
        cout<<"\n\t Element Found!";
        return;
    }
    else
        cout<<" False";

    for(auto i:adj[v])
        q.push(i);
    breadth_first(to_search, q, flag);
}

void tree::depth_first(int r, int to_search, bool &flag)
{
    cout<<"\n "<<r<<" Vs "<<to_search<<" --> ";
    if(r == to_search)
    {
        flag = true;
        cout<<" True";
        cout<<"\n\t Element Found!";
        return;
    }
    else
    {
        cout<<" False";
        for(auto i:adj[r])
        {
            if(!flag)
                depth_first(i, to_search, flag);
        }
    }
}


int main()
{
    tree obj;
    int to_search, choice;
    cout<<"\n ----------------------------------------- ";
    cout<<"\n Enter the element to search for : ";
    cin>>to_search;
    cout<<"\n Choose from the following --> ";
    cout<<"\n\t 1. Depth First Search (DFS) \n\t 2. Breadth First Search(BFS) \n\t 3. Exit";
    while(1)
    {
        cout<<"\n Your Choice = ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            {
                bool flag = false;
                obj.depth_first(obj.root, to_search, flag);
                if(!flag)
                    cout<<"\n\t Element not present!";
                cout<<"\n ----------------------------------------- \n";
                break;
            }
        case 2:
            {
                queue<int> q;
                q.push(obj.root);
                bool flag = false;
                obj.breadth_first(to_search, q, flag);
                if(!flag)
                    cout<<"\n\t Element not present!";
                cout<<"\n ----------------------------------------- \n";
                break;
            }
        case 3:
            return 0;
        }
    }
    return 0;
}
