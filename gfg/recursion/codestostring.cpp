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
int k = 0;
ll string_to_int(string n){
   
   stringstream geeks(n);
   int x = 0;
   geeks>>x;
   return x;

}

void codestostring(string prefix,string num,string* output){
   
   if(num.length() == 0){
    output[k] = prefix;
    k++;
    return;
   }
   
   int len = num.length();
   string newstring = num.substr(0,1);
   char n = newstring[0];
   if(n == '0') return;
   codestostring(prefix + (char)(n - '1' + 'a'),num.substr(1,len),output);

   if(len >= 2){
    string n = num.substr(0,2);
    ll in = string_to_int(n);
    if(in <= 26)  codestostring(prefix + (char)(in + 'a' - 1),num.substr(2,len),output);

   }
   
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin>>s;
    string output[1000];
    
    codestostring("",s,output);
    cout<<"[";
    int u = k-1;
    for(ll i = 0; i <k; i++){
      cout<<output[i];
      if(u){
        cout<<", ";
        u--;
      }
    }
    cout<<"]";
    return 0;
}
