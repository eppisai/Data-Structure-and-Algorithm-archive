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

    w(t)
    {
        int size;
        int xo = 0;
        cin >> size;
        for (int i = 1; i <= size; i++)
        {
            int temp;
            cin >> temp;
            if (temp & 1)
            {
                xo ^= i;
            }
        }

        if (xo > 0)
            cout << "Tom Wins\n";
        else
            cout << "Hanks Wins\n";
    }
    return 0;
}
