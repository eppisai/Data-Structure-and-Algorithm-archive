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

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
 
w(t){
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> a(n,vector<ll>(m,0));
    for(ll i = 0; i < n; i++){
        for(ll j =0; j <m; j++){
            cin>>a[i][j];
        }
    }
    ll ans = 0;
    for(ll i = 0; i < n; i++){
        for(ll j =0; j <m; j++){
            ll c1 = a[i][m-j-1];
            ll c2 = a[n-i-1][j];
            vector<int>b;
            b.push_back(a[i][j]);
            b.push_back(c1);
            b.push_back(c2);
            sort(b.begin(),b.end());
            a[i][j]=a[i][m-j-1]=a[n-i-1][j]=b[1];
            ans+=(ll)(b[2]-b[1])+(b[1]-b[0]);

        }
    }

    

}

    return 0;
}
