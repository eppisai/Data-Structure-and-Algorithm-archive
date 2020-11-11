You are given an array A of n elements and Q queries. Each query can be of following types:

1 L R: Print the minimum value in AL, AL+1, AL+2….,AR.
2 X Y: Update the value of Ax with Y.


#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define int              long long 
#define ll              long long 
#define ff              first
#define ss              second
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
ll n,q;

void buildtree(int *a,int start,int end,int *tree,int index){
   
   if(start == end){
       tree[index] = a[start];
       return;
   }

   //recursive case
   int mid = (start + end)/2;
   buildtree(a,mid+1,end,tree,2*index+1);
   buildtree(a,start,mid,tree,2*index);
   
   tree[index] = min(tree[2*index],tree[2*index +1]);
   return;

}

int query(int * tree,int ss,int se,int qs,int qe,int index){
    
    //no overlap
    if(qe < ss or qs > se) return inf;

    //complete overlap
    if(ss>=qs and se <= qe) {

      return tree[index];
    }

    //partial overlap
    int mid = (ss + se)/2;
    int left = query(tree,ss,mid,qs,qe,2*index);
    int right = query(tree,mid+1,se,qs,qe,2*index + 1);
    return min(left,right);


}

void updatequery(int * tree,int ss,int se,int i,int inc,int index){

    //out of bound 
    if(i > se or i < ss) return;

    //leaf node
    if(ss==se){
        tree[index] = inc;
        return;
    }
    //otherwise
    int mid = (ss + se)/2;
    updatequery(tree,ss,mid,i,inc,2*index);
    updatequery(tree,mid+1,se,i,inc,2*index + 1);
    tree[index] = min(tree[2*index], tree[2*index + 1]);
    return;
}

int32_t main()
{
    
    cin>>n>>q;
    int *tree = new int[4*n + 1];
    int a[n+1];
    for(ll i = 1; i <= n; i++) cin>>a[i];
    buildtree(a,1,n,tree,1);
    while(q--){
        ll o,a,b;
        cin>>o>>a>>b;
        if(o == 1){

            cout<<query(tree,1,n,a,b,1)<<"\n";
        }
        else {
            updatequery(tree,1,n,a,b,1);
        }
    }
    return 0;
}