#include<bits/stdc++.h>
using namespace std;

class graph{
    //adj list
    unordered_map<string,list<pair<string,int>>> l;
    public:
      void addedges(string x,string y,bool bidir,int wt){
          l[x].push_back(make_pair(y,wt));
          if(bidir){
              l[y].push_back(make_pair(x,wt));
          }
      }

      void printadjlist(){
          for(auto i : l){
              cout<<"Vertex "<<i.first<<"->";
              for(auto j : i.second){
                 cout<<j.first<<" "<<j.second<<",";
              }
              cout<<endl;
          }
      }
    
};




int main(){
    
    graph g;
    g.addedges("A","B",true,20);
    g.addedges("B","D",true,20);
    g.addedges("A","C",true,20);
    g.addedges("C","D",true,20);
    g.addedges("A","D",true,20);
    
    g.printadjlist();
    return 0;
}