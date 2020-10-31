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
#define mk                make_pair
#define w(t)              int t; cin>>t; while(t--)
const int MN = 2e5+7;
//array of vectors
vector<int> v[MN];

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

    w(t){
        string s;
        cin>>s;
        ll n=s.length();
        set<pair<pair<ll,ll>,pair<ll,ll>>> st;
        ll x=0,y=0,prevx=0,prevy=0,ans=0;
        for(ll i=0;i<n;i++)
        {
            if(s[i]=='N')
            y++;
            else if(s[i]=='S')
            y--;
            else if(s[i]=='E')
            x++;
            else
            x--;
            if(st.count({{x,y},{prevx,prevy}})||st.count({{prevx,prevy},{x,y}}))
            ans++;
            else
            ans+=5;
            st.insert(mk(mk(x,y),mk(prevx,prevy)));
            prevx=x;
            prevy=y;
        }
        cout<<ans<<endl;

    }
    return 0;
}
