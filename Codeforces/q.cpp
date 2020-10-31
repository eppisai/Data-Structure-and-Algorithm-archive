#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

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

vector<vector<ll>> multiply(vector<vector<ll>> x, vector<vector<ll>> y){

  vector<vector<ll>> t(2,vector<ll>(2,0));
  for(ll i = 0; i < 2; i++){
      for(ll j = 0; j < 2; j++){
          for(ll k = 0; k < 2; k++){
              t[i][j] = (t[i][j] + (x[i][k]*y[k][j]));
          }
      }
  } 
  return t; 
}


vector<vector<ll>> pow(vector<vector<ll>> t, ll n){
    vector<vector<ll>> ans(2,vector<ll>(2,1));
    if(n == 1) return t;
    if(n == 0) return ans;
    if(n&1){
        return(multiply(t,pow(t,n-1)));
    }
    ans = pow(t,n/2);
    return(multiply(ans,ans));
    
}

ll fibo(ll n){

  vector<ll>f = {0,1};
  if(n < 2){
      return f[n];
  }
  vector<vector<ll>> t(2,vector<ll>(2,0));
  t[0][1] = 1;
  t[1][0] = 1;
  t[1][1] = 1;
  t = pow(t,n-1);
  ll res = 0;
  for (ll i = 0; i < 2; i++)
  {
      res = (res + (t[1][i]*f[i]));
  }

  return res;
  
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
    w(t){
      ll m,n;
      cin>>n>>m;
      cout<<(fibo(m+2) - fibo(n+1))<<"\n"; 
    
    }

    return 0;
}

