#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int l = 0, r = 0, z = 0;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int ml = 0, bestl = 0;
    //only iterate till r !=n
    while (r < n)
    {
        if (a[r] == 1)
        {
            r++;
        }
        //it should be else if
        else if (a[r] == 0)
        {
            z++;
            r++;
        }
        while (z > k)
        {
            if (a[l] == 0)
            {
                z--;
                l++;
            }
            //it should be else if
            else if (a[l] == 1)
            {
                l++;
            }
        }
        //perform only if length is greater, not for equality
        if (ml < (r - l))
        {
            ml = r - l;
            //if there are multiple strings with maximum length, then it will store the left index of string that occurred first
            bestl = l;
        }
    }
    cout << ml;
    // to modify the 0 to 1
    for (int i = bestl; i < bestl + ml; i++)
    {
        a[i] = 1;
    }
    //cout<<"l = "<<l<<" r = "<<r;
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}