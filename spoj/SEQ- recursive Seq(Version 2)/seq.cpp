#include <bits/stdc++.h>

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
vector<ll> c, b, sm;

vector<vector<ll>> multiply(vector<vector<ll>> X1, vector<vector<ll>> X2)
{

    vector<vector<ll>> ans((k + 1), vector<ll>(k + 1));
    for (ll i = 0; i <= k; i++)
    {
        for (ll j = 0; j <= k; j++)
        {
            for (ll x = 0; x <= k; x++)
            {
                ans[i][j] = (ans[i][j] + (X1[i][x] * X2[x][j])%mod)%mod;
            }
        }
    }

    return ans;
}

vector<vector<ll>> pow(vector<vector<ll>> T, ll n)
{
    vector<vector<ll>> X2((k + 1), vector<ll>(k + 1));
    if (n == 0)
        return X2;
    if (n == 1)
        return T;

    if (n & 1)
        return (multiply(T, pow(T, n - 1)));
    vector<vector<ll>> X = pow(T, n / 2);
    return (multiply(X, X));
}

void compute(ll n, ll m, ll p)
{
    if (n <= k)
    {
        cout << (sm[n - 1] - sm[m - 2]) % p << "\n";
        return;
    }

    vector<ll> f1(k + 1);

    f1[0] = sm[k - 1];

    for (int i = 0; i < k; i++)
        f1[i + 1] = b[i];

    vector<vector<ll>> T((k + 1), vector<ll>(k + 1));
    T[0][0] = 1;
    T[1][0] = 0;

    for (int i = 0; i < k; i++)
    {
        T[0][i + 1] = c[k - i - 1];
        T[k][i + 1] = c[k - i - 1];
    }

    for (ll i = 1; i < k; i++)
    {
        for (ll j = 0; j <= k; j++)
        {
            if (j == (i + 1))
                T[i][j] = 1;
            else
                T[i][j] = 0;
        }
    }

    vector<vector<ll>> Tn = pow(T, (n - k));
    vector<vector<ll>> Tm = pow(T, (m - k));

    ll sn = 0, sm2 = 0;
    for (ll i = 0; i <= k; i++)
    {
        sn = (sn + (Tn[0][i] * f1[i])%mod)%mod;
        sm2 = (sm2 + (Tm[0][i] * f1[i])%mod)%mod;
    }

    if (m <= k)
        sm2 = sm[m - 2];

    cout << (sn - sm2) % p << "\n";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    w(t)
    {
        cin >> k;
        int s = 0;
        for (ll i = 0; i < k; i++)
        {
            int temp;
            cin >> temp;
            s += temp;
            b.push_back(temp);
            sm.push_back(s);
        }

        for (ll i = 0; i < k; i++)
        {
            int temp;
            cin >> temp;
            c.push_back(temp);
        }

        ll n, m, p;
        cin >> m >> n >> p;
        compute(n, m, p);
        b.clear();
        c.clear();
    }

    return 0;
}
