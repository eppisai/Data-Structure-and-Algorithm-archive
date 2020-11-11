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

int square_root(int n)
{
    int s = 0;
    int e = n;
    float ans = -1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        //check mid
        if (mid * mid == n)
        {
            return mid;
        }

        if (mid * mid < n)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            ans = mid - 1;
            e = mid - 1;
        }
    }

    float inc = 0.1;
    for (int times = 1; times <= p; times++)
    {
        while (ans * ans <= n)
            ans = ans + inc;
        //overshoot the value
        ans = ans - inc;
        inc = inc / 10;
    }
    return ans;
}

int32_t main()
{
    int n;
    cin >> n;
    cout << square_root(n) << endl;
    return 0;
}



