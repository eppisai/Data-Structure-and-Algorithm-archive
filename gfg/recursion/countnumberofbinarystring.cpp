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
int ans = 0;
void nonconscount(char *s, int idx, int n)
{

    //base case
    if (idx == n)
    {
        s[idx] = '\0';
        cout<<s<<"\n";
        ans++;
        return;
    }

    //recursive case
    if (s[idx - 1] == '0')
    {
        s[idx] = '1';
        nonconscount(s, idx + 1, n);
        s[idx] = '0';
        nonconscount(s, idx + 1, n);
    }

    else if (s[idx - 1] == '1')
    {
        s[idx] = '0';
        nonconscount(s, idx + 1, n);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    w(t)
    {
        ans = 0;
        int n;
        cin >> n;
        char s[n];
        s[0] = '1';
        nonconscount(s, 1, n);
        s[0] = '0';
        nonconscount(s, 1, n);
        cout << ans << "\n";
    }
    return 0;
}
