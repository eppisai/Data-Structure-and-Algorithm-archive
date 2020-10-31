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
ll ans[1000003], lastocc[1000003], ar[1000003];

int main()
{
    ll n;
    cin>>n;
    double an = 0;
    ans[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin>>ar[i];
        ans[i] = ans[i - 1] + (i - lastocc[ar[i]]);
        an += ans[i];
        lastocc[ar[i]] = i;
    }

    an = (2*(an - n) +n)/(n*n*1.0);

    cout<<ps(an, 6)<<"\n";

    return 0;
}





