#include <iostream>
using namespace std;
#define INT_MAX 1000000000;

int main()
{
    int t;
    cin >> t;
    int n, k;
    while (t--)
    {
        cin >> n >> k;
        int ans = INT_MAX;
        int j = INT_MAX;

        //factorization of k;
        int occ = 0;
        for (int i = 2; i * i <= k; i++)
        {
            if (k % i == 0)
            {
                occ = 0;
                while (k % i == 0)
                {
                    occ++;
                    k = k / i;
                }

                //find out the power's of i in n!
                int tmp = 0;
                long long p = i;
                while (p <= n)
                {
                    tmp += n / p;
                    p = p * i;
                }
                ans = min(ans, tmp / occ);
            }
        }

        if (k > 1)
        {
            int cnt = 0;
            int p = k;
            while (p <= n)
            {
                cnt += n / p;
                p *= k;
            }
            ans = min(ans, cnt);
        }

        if (ans == k)
        {
            ans = 0;
        }

        cout << ans << "\n";
    }

    return 0;
}