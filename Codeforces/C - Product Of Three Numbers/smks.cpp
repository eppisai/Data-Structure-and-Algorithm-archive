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

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> pf;
        for (int i = 2; i * i < n; i++)
        {
            if (n % i == 0)
            {
                int count = 0;
                while (n % i == 0)
                {
                    count++;
                    n = n / i;
                }
                pf.push_back(make_pair(i, count));
            }
        }

        if (n > 1)
        {
            pf.push_back(make_pair(n, 1));
        }

        if (pf.size() >= 3)
        {
            cout << "YES\n";
            for (auto x : pf)
                cout << pow(x.first, x.second) << " ";
            cout << "\n";
        }

        else
            (pf.size() == 2)
            {
                int tp = 0;
                for (auto x : pf)
                    tp += x.second;
                if (tp <= 3)
                    cout << "NO\n";
                else
                {
                    cout << "YES\n";
                    for (auto x : pf)
                        cout << pow(x.first, x.second) << " ";
                }
            }
    }

    return 0;
}