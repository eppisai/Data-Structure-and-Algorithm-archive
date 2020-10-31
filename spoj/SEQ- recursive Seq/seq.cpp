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
#define mod 1000000000
#define inf 1e18
#define ps(x, y) fixed << setprecision(y) << x
#define mk(arr, n, type) type *arr = new type[n];
#define w(t)  \
    int t;    \
    cin >> t; \
    while (t--)
ll k;
vector<ll> c, b;

vector<vector<ll>> multiply(vector<vector<ll>> X1, vector<vector<ll>> X2)
{

    vector<vector<ll>> ans(k, vector<ll>(k));
    for (ll i = 0; i < k; i++)
    {
        for (ll j = 0; j < k; j++)
        {
            for (ll x = 0; x < k; x++)
            {
                ans[i][j] = (ans[i][j] + (X1[i][x] * X2[x][j]) % mod) % mod;
            }
        }
    }

    return ans;
}

vector<vector<ll>> pow(vector<vector<ll>> T, ll n)
{

    if (n == 1)
        return T;

    if (n & 1)
        return (multiply(T, pow(T, n - 1)));
    vector<vector<ll>> X = pow(T, n / 2);
    return (multiply(X, X));
}

void compute(ll n)
{

    if (n <= k)
    {
        cout << b[n - 1] << "\n";
        return;
    }

    vector<vector<ll>> T(k, vector<ll>(k));

    for (ll i = 0; i < k; i++)
    {
        for (ll j = 0; j < k; j++)
        {
            if (i < (k - 1))
            {
                if (j == (i + 1))
                {
                    T[i][j] = 1;
                }

                else
                    T[i][j] = 0;
            }
            else
            {
                T[i][j] = c[k - j - 1];
            }
        }
    }

    T = pow(T, (n - 1));

    // for (ll i = 0; i < k; i++)
    // {
    //     for (ll j = 0; j < k; j++)
    //     {
    //         cout << T[i][j] << " ";
    //     }

    //     cout << "\n";
    // }

    ll ans = 0;
    for (ll i = 0; i < k; i++)
    {
        ans = (ans + (b[i]) * (T[0][i]) % mod) % mod;
    }

    cout << ans << "\n";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int temp;
    w(t)
    {
        cin >> k;
        for (ll i = 0; i < k; i++)
        {
            cin >> temp;
            b.push_back(temp);
        }

        for (ll i = 0; i < k; i++)
        {
            cin >> temp;
            c.push_back(temp);
        }

        ll n;
        cin >> n;
        compute(n);
        b.clear();
        c.clear();
    }

    return 0;
}
