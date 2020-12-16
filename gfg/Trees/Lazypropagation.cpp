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

int lazy[10000] = {0};

void updatelazy(int *tree,int ss,int se,int l,int r,int inc,int index){

   //before going down, resolve the current value if it exists
   if(lazy[index]!= 0){

       tree[index] += lazy[index];

       //non leaf node
       if(ss != se){
          lazy[2*index] += lazy[index];
          lazy[2 * index + 1] += lazy[index];
       }
       lazy[index] = 0; //clear the lazy value at the current node
   }

   //base case
   // no overlap
   if(ss > r or se < l) return;

   //recursive case - complete overlap
   if(ss >= l and se <= r){
       tree[index] += inc;

       //create a new lazy value for children node
       if(ss != se){
         lazy[2*index] += inc;
         lazy[2 * index + 1] += inc;
       }
       return;
   }

   //recursive case   partial overlap
   int mid = (ss + se)/2;
   updatelazy(tree,ss,mid,l,r,inc,2*index);
   updatelazy(tree, mid + 1, se, l, r, inc, 2 * index + 1);
   //update the current node
   tree[index] = min(tree[2*index],tree[2*index+1]);
   return;
}

int querlazy(int *tree,int ss,int se,int qs,int qe,int index){

    //resolve the lazy value at the current node
    if(lazy[index] != 0){
        tree[index] += lazy[index];

        //non leaf node
        if(ss != se){
            lazy[2*index] += lazy[index];
            lazy[2 * index + 1] += lazy[index];
        }

        lazy[index] = 0;
    }

    //query logic - no overlap
    if(ss > qs or se < qs) return inf;

    //complete overlap
    if(ss >= qs or se <= qe){
        return tree[index];
    }
    
    //partial overlap
    int mid = (ss + se)/2;
    int left = querylazy(tree,ss,mid,qs,qe, 2*index);
    int right = querylazy(tree, mid+1, se, qs, qe, 2 * index + 1);
    return;
     
}

void build(int *a,int s,int e,int * tree,int index){

    if(s == e){
        tree[index] = a[s];
        return;
    }

    // recursive case
    int mid = (s+e)/2;
    build(a,s,mid,tree,2*index);
    build(a,mid+1,e,tree, 2*index + 1);
    tree[index] = min(tree[2*index], tree[2*index + 1]);
    return;
}


int32_t main()
{
    int a[] = {1,3,2,-5,6,4};
    int n = sizeof(a)/sizeof(int);
    int *tree = new int[4*n + 1];
    build(a,0,n-1,tree,1);


    updatelazy(tree,0,n-1,0,2,10,1);
    updatelazy(tree, 0, n - 1, 0, 4, 10, 1);
    cout<<"Q1 1-1"<<querlazy(tree,0,n-1,1,1,1)<<endl;
    return 0;
}