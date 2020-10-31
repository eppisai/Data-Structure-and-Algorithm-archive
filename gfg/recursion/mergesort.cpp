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

void merge(ll *a,ll start,ll end){
	ll mid = start + end >> 1;
	ll i = start,j = mid,k = start;
	ll temp[100];
	while(i <= mid &&  j <= end){
		if(a[i] < a[j]){
			temp[k++] = a[i++];
		}
		else{
			temp[k++] = a[j++];
		}
	}

	while(i <= mid) temp[k++] = a[i++];
	while(j <= end) temp[k++] = a[j++];

	for(ll i = start; i <= end; i++) a[i] = temp[i];
}

void mergeesort(ll *a,ll start,ll end){

	if(start <= end) return;

    ll mid = start + end >> 1;

    mergeesort(a,start,mid);
    mergeesort(a,mid + 1,end);
    merge(a,start,end);
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

    ll n;
    cin>>n;
    ll a[n];
    for(ll i = 0; i < n; i++) cin>>a[i];
    mergeesort(a,0,n - 1);
    for(ll i = 0;i < n; i++) cout<<a[i]<<" ";
    cout<<"\n";
    return 0;
}
