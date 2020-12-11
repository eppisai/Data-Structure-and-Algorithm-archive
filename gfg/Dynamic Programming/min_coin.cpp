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

int mincoinsTD(int n,int coins[],int T,int dp[]){

    //base case
    if(n == 0) return 0;

    if(dp[n] != 0) return dp[n];
    
    //recursive case
    int ans = INT_MAX;
    for(int i = 0; i < T; i++){
        if(n - coins[i] >= 0){
          int subprob = mincoinsTD(n - coins[i],coins,T,dp);
          ans = min(ans,subprob + 1);
        }
    }
    dp[n] = ans;
    return dp[n];
}

int mincoinsBU(int n,int coins[],int T){
 int dp[100] = {0};

 for(int i = 1; i <= n; i++){
   dp[i] = INT_MAX;
   for(int j = 0; j < T; j++){
     if(n - coins[i] >= 0){
       int subprob = dp[n - coins[i]];
       dp[i] = min(dp[i],subprob+1);
     }
   }
 }
 return dp[n];
}
 
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
  int n = 25;
  int coins[] = {1,7,10};
  int dp[100] = {0};
  int T = 3;
  cout<< mincoinsTD(n,coins,T,dp)<<"\n";
  cout<<mincoinsBU(n,coins,T)<<"\n";
  return 0;
}

