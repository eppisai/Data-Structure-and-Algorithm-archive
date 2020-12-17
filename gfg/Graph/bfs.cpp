#include<bits/stdc++.h>
using namespace std;

template<typename T>

class Graph{
    map<T,list<T>> l;

    public:
      void addedges(int x,int y){
          l[x].push_back(y);
          l[y].push_back(x);
      }

      void bfs(T src){
        
        T node = q.front();
        q.pop();

        while(!q.empty()){
            T node = q.front();
            q.pop();

            for(int nbr:l[node]){
                if(!visited[nbr]){
                    q.push(nbr);
                    //mark that nbr as visited
                    visited[nbr] = true;
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