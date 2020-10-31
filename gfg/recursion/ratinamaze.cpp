#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

using namespace __gnu_pbds;
using namespace std;

#define ll                long long
#define ff                first
#define ss                second
#define pb                push_back
#define mp                make_pair
#define pii               pair<int,int>
#define vi                vector<int>
#define mii               map<int,int>
#define pqb               priority_queue<int>
#define pqs               priority_queue<int, vector<int>, greater<int>>
#define setbits(x)        __buildin_popcountll(x)
#define mod               1000000007
#define inf               1e18
#define ps(x,y)           fixed<<setprecision(y)<<x
#define mk(arr,n,type)    type *arr=new type[n];
#define w(t)              int t; cin>>t; while(t--)
const int MN = 2e5+7;
//array of vectors
vector<int> v[MN];

bool ratinamaze(char maze[10][10],int soln[10][10],int i,int j,int m,int n){
	if(i == m && j == n){
       soln[m][n] = 1;
       
       for(int i = 0; i <= m; i++){
       	 for(int j = 0; j <= n; j++) cout<<soln[i][j]<<" ";
       	 	cout<<endl;
       }
       
       cout<<endl;
       return true;
	}

	if(i > m || j > n) return false;

	if(maze[i][j] == 'X') return false;

	soln[i][j] = 1;
	bool right = ratinamaze(maze,soln,i,j+1,m,n);
	bool down = ratinamaze(maze,soln,i+1,j,m,n);

    //backtrack step
    soln[i][j] = 0;
 
    if(right || down) return true;
    return false;
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

   char maze[10][10] = {
   	"0000",
   	"00X0",
   	"000X",
   	"0X00",
   };

   int soln[10][10] = {0};
   int m = 4,n = 4;

   bool  ans = ratinamaze(maze,soln,0,0,m-1,n-1);
   
   if(ans == false) cout<<"path does not exist";
    return 0;
}


