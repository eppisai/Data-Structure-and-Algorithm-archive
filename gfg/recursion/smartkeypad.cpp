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

string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
string searchIn [] = {
            "prateek", "sneha", "deepak", "arnav", "shikha", "palak",
            "utkarsh", "divyam", "vidhi", "sparsh", "akku"
    };
ll a[100];

void printstring(string n,ll k,string s){

	if(k == n.length()){
		for(ll i = 0; i < 11; i++){
			if(searchIn[i].find(s) != string::npos and a[i] == 0){
                 cout<<searchIn[i]<<"\n";
                 a[i] = 1;
			}
		}
		return;
	}

	ll num  = n[k] - '0';
    k++;
	for(ll i = 0 ;i < table[num].size() ; i++){
       s.push_back(table[num][i]);
       printstring(n,k,s);
       s.pop_back();
	}


}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
for (int i = 0; i < 100; ++i)
{
   	a[i] = 0;
}   
string n;
cin>>n;
string s;
printstring(n,0,s);
 return 0;
}
