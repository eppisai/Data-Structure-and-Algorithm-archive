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

int csum[100005], pre[100005];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    w(t)
    {
        int n, flag = 0, findex, lindex;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] % n == 0 && flag == 0)
            {
                cout << 1 << "\n"
                     << i + 1 << "\n";
                flag = 1;
            }
        }

        if (flag == 0)
        {
            for (int i = 0; i < n; i++)
                pre[i] = 0;
            pre[0] = 1;
            for (lindex = 1; lindex < n; lindex++)
            {
                csum[lindex] = csum[lindex - 1] + a[lindex - 1];
                if (pre[csum[lindex]])
                    break;
                pre[csum[lindex]]++;
            }

            for (findex = 0; findex <= lindex; findex++)
                if (csum[lindex] == csum[findex])
                    break;
            cout << (lindex - findex) << "\n";
            for (++findex; findex <= lindex; findex++)
            {
                cout << findex;
                if (findex != lindex)
                    cout << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}
