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


int minsteps(int n,int dp[]){

    //base case
    if(n == 1) return 0;
    if(dp[n] != 0) return dp[n];
    
    int op1,op2,op3;
    op1 = op2 = op3 = 101;

    if(n%3 == 0) op1 = minsteps(n/3,dp) + 1;
    if(n%2 == 0) op2 = minsteps(n/2,dp) + 1;
     op3 = minsteps(n-1,dp) + 1;

    int ans = min(min(op1,op2),op3);
    return dp[n] = ans;
}
 
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
 int n;
 cin>>n;
 int dp[1000] = {0};
 cout<<minsteps(n,dp);
  return 0;
}