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
#define mod               10000007
#define inf               1e18
#define ps(x,y)           fixed<<setprecision(y)<<x
#define mk(arr,n,type)    type *arr=new type[n];
#define w(t)              int t; cin>>t; while(t--)
const int MN = 2e5+7;
//array of vectors
vector<int> v[MN];

ll modmulti(ll a,ll b){
  a %= mod;
  ll res = 0;
  while(b){
    if(b&1ll){
      res = ((res%mod) + (a%mod))%mod;
    }

    a = ((a%mod) * (2%mod))%mod;
    b /= 2;
  } 
  return res;
}

ll modexpo(ll a,ll b){
   a %=mod;
   ll res =  1;
   while(b){
      if(b&1ll) {
        res = modmulti(res,a);
        res%=mod;
      }
      a = modmulti(a,a);
      a %= mod;
      b /= 2;
   }

   return res;
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    
    
     ll n,k;
     while(cin>>n>>k){
      if(n == 0 && k == 0) continue;
      ll first = modexpo(n-1,k);
      first = modmulti(first,2);
      ll sec = modexpo(n - 1, n - 1);
      sec = modmulti(sec,2);
      ll third = modexpo(n,n);
      ll fourth = modexpo(n,k);
      ll ans = ((first%mod) + (sec%mod) + (third%mod) + (fourth%mod))%mod;
      cout<<ans<<"\n";
     }
     

    
    return 0;
}

