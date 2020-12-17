#include<bits/stdc++.h>
using namespace std;

template<typename T>

class Graph{
    map<T,list<T>> l;
    T visited[1000];

    public:
      void addedges(int x,int y){
          l[x].push_back(y);
          l[y].push_back(x);
      }

      void bfs(T src){
        
        map<T, int> dist;
        queue<T> q;

        //all other nodes will have int_max
        for(auto node_pair:l){
            T node = node_pair.first;
            dist[node] = INT_MAX;
            
        }

        q.push(src);
        dist[src] = 0;

        

        while(!q.empty()){
            T node = q.front();
            q.pop();

            for(int nbr:l[node]){
                if(dist[nbr] == INT_MAX){
                    q.push(nbr);
                    //mark that nbr as visited
                    dist[nbr] = dist[node] + 1;
                }
            }
        }
      }
};

int main(){
   Graph<int> g;
   g.addedges(0,1);
   g.addedges(1,2);
   g.addedges(2,3);
   g.addedges(3,4);
   g.addedges(4,5); 

   g.bfs(0);

   return 0;
}