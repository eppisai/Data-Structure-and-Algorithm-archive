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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    w(t)
    {
        ll n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        ll consecutivelosses = 0, l = 0, w = 0, consecutivewins = 0;
        vector<ll> cl, cw;
        for (ll i = 0; i < n; i++)
        {
            if (s[i] == 'L')
            {
                l++;
                if (i == 0 || s[i - 1] == 'L')
                {
                    consecutivelosses++;
                }
                if (consecutivewins != 0)
                    cw.pb(consecutivewins);
                consecutivewins = 0;
            }
            if (s[i] == 'W')
            {
                w++;
                if (i == 0 || s[i - 1] == 'W')
                {
                    consecutivewins++;
                }
                if (consecutivelosses != 0)
                    cl.pb(consecutivelosses);
                consecutivelosses = 0;
            }
        }
        if (k >= l)
        {
            cout << 2 * n - 1 << "\n";
            continue;
        }

        if (w == 0)
        {
            if (k == 0)
                cout << 0 << "\n";
            else
                cout << 2 * k - 1 << "\n";
            continue;
        }
        ll ans = (2 * w - cl.size()), ls = 0;
        sort(cl.begin(), cl.end());
        for (ll i = 0; i < cl.size(); i++)
        {
            if (cl[i] <= k)
            {
                k -= cl[i];
                ans += 2 * cl[i];
                ls++;
            }
        }
        ans = ans + ls;
        cout << ans << "\n";
    }

    return 0;
}
