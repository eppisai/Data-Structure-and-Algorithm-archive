#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    cin.get();
    string s[n + 1];
    for (int i = 0; i < n; i++)
        getline(cin, s[i]);
    for (int i = 0; i < n; i++)
        cout << s[i] << " ";

    return 0;
}