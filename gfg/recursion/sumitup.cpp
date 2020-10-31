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
ll n;
ll t;
vector<ll> ans;
set<vector<ll>> s;
void solve(ll *a,ll su,ll idx){
  if(su == t){
    s.insert(ans);
    return;	
  }
  if(idx == n){
  	return;
  } 
  if(su + a[idx] <= t){
  	   ans.push_back(a[idx]);
       solve(a,su + a[idx],idx+1);
       ans.pop_back();
  }
  	solve(a,su,idx+1);

}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

   
   cin>>n;
   ll a[n];
   for(ll i = 0;i < n; i++) cin>>a[i];
   sort(a, a+n);
   cin>>t;
   solve(a,0,0);
   for(auto i : s){
     for(auto j : i){
         cout<<j<<" ";
     }
     cout<<"\n";
   }	

    return 0;
}
