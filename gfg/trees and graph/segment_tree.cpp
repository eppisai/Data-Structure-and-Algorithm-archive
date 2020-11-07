#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define mii map<int, int>
#define pqb priority_queue<int>
#define pqs priority_queue<int, vi, greater<int>>
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define mod 1000000007
#define inf 1e18
#define ps(x, y) fixed << setprecision(y) << x
#define mk(arr, n, type) type *arr = new type[n];
#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void buildtree(int *a, int start, int end, int *tree, int index)
{
    if (start == end)
    {
        tree[index] = a[start];
        return;
    }
    //recursive case
    int mid = (start + end) / 2;
    buildtree(a, start, mid, tree, 2 * index);
    buildtree(a, mid + 1, end, tree, 2 * index + 1);
    tree[index] = min(tree[2 * index], tree[2 * index + 1]);
    return;
}

int query(int *tree, int ss, int se, int qs, int qe, int index)
{

    //complete overlap
    if (ss >= qs and se <= qe)
        return tree[index];

    //no overlap
    if (qe < ss or qs > se)
        return inf;

    //partial overlap
    int mid = (ss + se) / 2;
    int left = query(tree, ss, mid, qs, qe, 2 * index);
    int right = query(tree, mid + 1, se, qs, qe, 2 * index + 1);
    return min(left, right);
}

void update(int *tree,int ss, int se,int i,int increment,int index){

 // case where the i is out of bounds
 if(i > se or i < ss){
     return;
 }

 //leaf node
 if(ss == se){
     tree[index] += increment;
     return;
 }

 //otherwise
 int mid = (ss + se)/2;
 update(tree, ss,mid, i,increment,2*index);
 update(tree,mid+1,se,i,increment,2*index + 1);
 tree[index] = min(tree[2*index], tree[2*index + 1]);

}

void updateRange(int *tree,int ss,int se,int l,int r,int inc,int i){

    //out of bounds
    if(l > se or r < ss) return;

    //leaft node
    if(ss == se){
        tree[index] += inc;
        return;
    } 

    //recursiv case
    int mid = (ss + se)/2;
    updateRange(tree,ss,mid,l,r,inc,2*index);
    updateRange(tree,mid+1,se,l,r,inc, 2*index + 1);
    tree[index] = min(tree[2*index],tree[2*index + 1]);
    return;
}

int32_t main()
{
    int a[] = {1, 3, 2, -5, 6, 4};
    int n = sizeof(a) / sizeof(int);
    int *tree = new int[4 * n + 1];
    buildtree(a, 0, n - 1, tree, 1);
    //for(int i = 1; i <=13; i++) cout<<tree[i]<<" ";
    // int q;
    // cin >> q;
    // while (q--)
    // {
    //     int l, r;
    //     cin>>l>>r;
    //     cout << query(tree, 0, n - 1, l, r, 1) << endl;
    // }
    //update(tree,0,n,n-1,3,10,1);




    return 0;
}