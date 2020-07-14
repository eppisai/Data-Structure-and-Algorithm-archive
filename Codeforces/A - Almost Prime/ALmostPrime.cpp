#include <bits/stdc++.h>
using namespace std;

void prime(int *p)
{
    for (int i = 2; i < 3005; i++)
    {
        if (p[i] == 0)
        {

            for (int j = i * 2; j < 3005; j += i)
            {
                p[j]++;
                if (j == 2)
                    break;
            }
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k = 0;
    cin >> n;
    int p[3005] = {0};
    prime(p);
    for (int i = 0; i <= n; i++)
        if (p[i] == 2)
            k++;
    cout << k;
    return 0;
}
