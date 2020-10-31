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

ll modular_multiplication(ll a, ll b, ll n)
{
    ll res = 0;
    while (b)
    {
        if (b & 1ll)
            res += a;
        a *= 2;
        b /= 2;
        res %= n;
        a %= n;
    }
    return res;
}

ll modular_exponentiation(ll a, ll b, ll n)
{
    ll res = 1;
    while (b)
    {
        if (b & 1ll)
        {
            res = modular_multiplication(res, a, n);
            res %= n;
        }
        a = modular_multiplication(a, a, n);
        a %= n;
        b /= 2;
    }
    return res;
}

bool miller_rabin(ll n)
{
    if (n == 1)
        return false;
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;
    //now, since n is odd, so n-1 is even
    ll d = n - 1, s = 0;
    while (d % 2 == 0)
    {
        s++;
        d /= 2;
    }
    // n - 1 = d*pow(2,s)
    //d is an odd number
    vector<ll> a({2, 3, 5, 7, 11, 13, 17, 19, 23});
    //a represemts a random number
    for (ll i = 0; i < a.size(); i++)
    {
        if (a[i] > (n - 2))
            continue;
        // now i need (a[i]^d)%n
        ll ad = modular_exponentiation(a[i], d, n);
        if (ad % n == 1)
            continue;
        bool prime = false;
        for (ll r = 0; r <= (s - 1); r++)
        {
            // (2^r)%n
            ll rr = modular_exponentiation(2, r, n);
            // a^(d*2*i))%n
            ll ard = modular_exponentiation(ad, rr, n);
            if (ard % n == n - 1)
            {
                prime = true;
                break;
            }
        }
        if (prime == false)
            return false;
    }
    return true;
}

void solve()
{
    ll n;
    cin >> n;
    if (miller_rabin(n))
    {
        cout << "prime\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    w(t)
    {
        solve();
    }

    return 0;
}
//lower limit 38...something