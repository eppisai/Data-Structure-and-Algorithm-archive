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

ll powe(ll a, ll b){
    if(b == 0) return 1;
    ll smallpower = powe(a,b/2);
    smallpower %= mod;
    smallpower = (smallpower*smallpower)%mod;
    
    if(b&1){
        return (a*smallpower)%mod;
    }
    return smallpower;


}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
 w(t){
     string a,b;
     cin>>a>>b;
     ll a1 = 0,b1 = 0;
     for(ll i = 0; i < a.size(); i++){
         a1 = (a1*10)%mod + (a[i] - '0')%mod;
         a1 %= mod;
     }
     for(ll i = 0; i < b.size(); i++){
         b1 = (b1*10)%(mod - 1) + (b[i] - '0')%(mod - 1);
         b1 %=mod;
     }
     cout<<powe(a1,b1)<<"\n";
 }

	return 0;
}