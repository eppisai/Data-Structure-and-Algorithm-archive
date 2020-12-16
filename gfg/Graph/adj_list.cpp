#include<bits/stdc++.h>
using namespace std;

class graph{
    int v;
    //pointer to an array of list
    list<int> *l;
    public:
     graph(int v){
         this->v = v;
         l = new list<int>[v];
     }

     void addedges(int x,int y){
        l[x].push_back(y);
        l[y].push_back(x);
     }

     void printadjlist(){

         //iterate over all the vertices
         for(int i = 0;i<v; i++){
             cout<<"Vertex "<<i<<" ->";
             for(int nbr: l[i]){
                 cout<<nbr<<",";
             }
             cout<<endl;
         }
     }
    
};




int main(){
    
    graph g(4);
    g.addedges(0,1);
    g.addedges(0,2);
    g.addedges(2,3);
    g.addedges(1,2);
    g.printadjlist();
    return 0;
}