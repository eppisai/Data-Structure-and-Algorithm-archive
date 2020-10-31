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

void replacePi(char a[], int i)
{
    //base case
    if (a[i] == '\0' or a[i + 1] == '\0')
    {
        return;
    }

    //look for pi at current location
    if (a[i] == 'p' and a[i + 1] == 'i')
    {
        //SHIFTING followed by replacement
        int j = i + 2;
        //take j to the end of the array
        while (a[j] != '\0')
        {
            j++;
        }

        while (j >= i + 2)
        {
            a[j + 2] = a[j];
            j--;
        }
        //replace + recursion
        a[i] = '3';
        a[i + 1] = '.';
        a[i + 2] = '1';
        a[i + 3] = '4';
    }
    else
    {
        //go to the next position
        replacePi(a, i + 1);
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    return 0;
}
