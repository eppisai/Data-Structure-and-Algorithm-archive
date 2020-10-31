
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, 
             tree_order_statistics_node_update> pbds;

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

string addi(string k1, string k2){
    ll sie = (k1.size() > k2.size()) ? k2.size(): k1.size();
    ll sie2 = (k1.size() > k2.size()) ? k1.size(): k2.size();
    string a = (k1.size() > k2.size()) ? k1: k2;
    vector<ll> ans;
    string an;
    ll carry = 0,index = 0;
    for(ll i = 0; i < sie; i++){
        ll place = k1[k1.size() - 1 - i] - '0' + k2[k2.size() - 1 - i] - '0' + carry;
        carry = place/10;
        place = place%10;
        ans.push_back(place + '0');
        index++;
    }
    
    for(ll i = (sie2 - sie - 1); i >= 0; i--){
        ll place = a[i] - '0' + carry;
        carry = place/10;
        place = place%10;
        ans.push_back(place  + '0');
        index++;
    }

    
    while(carry){
       ans.push_back(carry + '0');
       index++;
       carry = carry/10;
    }
    index;
    for(int i = index - 1; i >= 0; i--){
        an += ans[i];
    }
    
    return an;
    
}

int main()
{
       string x;
       cin>>x;
    //   string k1 = f(x);
    //   string k2 = g(x);
       cout<<addi("399", "99");
       return 0;
}
