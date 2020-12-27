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

int lcs(string x,string y,int lx,int ly){
   
   //base case
   if(lx <= 0 or ly <= 0) return 0;
   if(x[lx - 1] == y[ly - 1]){
       return (lcs(x,y,lx-1,ly-1) + 1);
   }
   return max(lcs(x,y,lx,ly-1),lcs(x,y,lx-1,ly));

}

 
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    string X = "AGGTAB";  
    string Y = "GXTXAYB";   
      
    cout << "Length of LCS is " 
         << lcs( X, Y, 6, 7);  
  return 0;
}

