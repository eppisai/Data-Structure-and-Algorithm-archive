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
vector<string> output;

void generatep(string &out,int idx,int n,int op,int cl){
   
    if(idx == 2*n){
        output.push_back(out);
        return;
    }
    
    if(op < n){
        out.push_back('(');
        idx++;
        op++;
        generatep(out,idx,n,op,cl);
        idx--;
        op--;
        out.pop_back();
    }
    if(cl < op){
        out.push_back(')');
        idx++;
        cl++;
        generatep(out,idx,n,op,cl);
        idx--;
        cl--;
        out.pop_back();
    }
    
  }

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

    int n;
    cin>>n;
    string s;
    generatep(s,n,0,0,0);     
    cout<<"[";
    cout<<output[0];
    for(ll i = 1; i < output.size(); i++){
        cout<<","<<output[i];
    }
    cout<<"]";
    return 0;
}
