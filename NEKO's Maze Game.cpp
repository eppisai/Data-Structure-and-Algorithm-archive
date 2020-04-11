#include<iostream>
using namespace std;

int main(){
  int q,n;
  cin>>n>>q;
  int maze[2][n];

  for(int i=0;i<2;i++)
     { for(int j=0; j<n;j++) maze[i][j] = 0;}

  for(int h=0;h<q;h++)
  { int n1,n2,sum0=0,sum1=0;
    cin>>n1>>n2;
    if(maze[n1][n2]==1) maze[n1][n2] = 0;
    if(maze[n1][n2]==0) maze[n1][n2] = 1;
    for(int j=0; j<n ; j++)
      {
          sum0 += maze[0][i];
          sum1 +=maze[1][i];
      }
    if(sum0 == 0 || sum1 == 0) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
  }
  return 0;
}


