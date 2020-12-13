#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define mii map<int, int>
#define pqb priority_queue<int>
#define pqs priority_queue<int, vector<int>, greater<int>>
#define setbits(x) __buildin_popcountll(x)
#define mod 1000000007
#define inf 1e18
#define ps(x, y) fixed << setprecision(y) << x
#define mk(arr, n, type) type *arr = new type[n];
#define w(t)  \
    int t;    \
    cin >> t; \
    while (t--)
const int MN = 2e5 + 7;
//array of vectors
vector<int> v[MN];

int profit(int wines[],int i,int j,int y,int dp[][100])
{

    //base case
    if(i > j) return 0;
    if (dp[i][j] != 0)
        return dp[i][j];

    int op1, op2;
    op1 = wines[i]*y + profit(wines,i+1,j,y+1,dp);
    op2 = wines[j] * y + profit(wines, i , j-1, y + 1, dp);
    return dp[i][j] = max(op1,op2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int wines[] = {2,3,5,1,4};
    int n = 5;
    int y = 1;
    dp[100][100] = {0} 
    cout << profit(wines,0,n-1, dp);
    return 0;
}