#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    ll n;
    cin >> n;
    ll ar[n];

    for (ll i = 0; i < n; i++)
    {
        cin >> ar[i];
    }

    ll first = 0, last, length, ans = 2;
    if (n < 2)
        ans = n;
    for (ll i = 2; i < n; i++)
    {
        if (ar[i] == ar[i - 1] + ar[i - 2])
        {
            last = i;
            length = last - first + 1;
            ans = max(ans, length);
        }
        else
        {
            first = i - 1;
        }
    }

    // sort(ar, ar + n);
    // if(ar[0] = ar[n-1]){
    //     if(ar[2] = ar[1] )
    // }

    cout << ans << "\n";
    return 0;
}
