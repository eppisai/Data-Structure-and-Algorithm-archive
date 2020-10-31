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

bool check(ll board[10][10],ll n,ll i,ll j,ll solution[10][10],ll &count){
    
    
    


    if(board[i][j] != 1 or i < 0 or j < 0 or i >= n or j >= n){
    	ll c;
    	for(ll i1 = 0 ;i1 < n; i1++){
    	 for(ll j1 = 0; j1 < n; j1++){
    		if(solution[i1][j1] == 8) c++;
    	 }
        }

        count = min(c,count);
    	return false;
    } 

    solution[i][j] = 8;
    bool a = check(board,n,i+1,j+2,solution,count);
    bool h = check(board,n,i+2,j+1,solution,count);
    bool g = check(board,n,i-2,j+1,solution,count);
    bool f = check(board,n,i-1,j+2,solution,count);
    bool e = check(board,n,i-1,j-2,solution,count);
    bool d = check(board,n,i-2,j-1,solution,count);
    bool c = check(board,n,i+2,j-1,solution,count);
    bool b = check(board,n,i-1,j-2,solution,count);
    solution[i][j] = 1;

    if(a or b or c or d or e or h or g or h) return true;

    ll c1;
    for(ll i1 = 0 ;i1 < n; i1++){
     for(ll j1 = 0; j1 < n; j1++){
    		if(solution[i1][j1] == 1) c1++;
    	 }
      }

      count = min(c1,count);
      return false;

}


int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

    ll n;
    cin>>n;
    ll board[10][10],solution[10][10];

    for(ll i = 0 ;i < n; i++){
    	for(ll j = 0; j < n; j++){
    		cin>>board[i][j];
    		solution[i][j] = 0;
    	}
    }

    ll count;
    for(ll i1 = 0 ;i1 < n; i1++){
     for(ll j1 = 0; j1 < n; j1++){
    		if(board[i1][j1] == 8) count++;
    	 }
      }

    bool p = check(board,n,0,0,solution,count);

    cout<<count;
    return 0;
}
