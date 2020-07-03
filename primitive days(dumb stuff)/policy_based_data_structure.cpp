#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n,inv = 0;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n;i++) cin>>arr[i];
    pbds st;

    for(int i = 0; i < n;i++){
       
       inv +=st.size() - order_of_key(arr[i]);
       st.insert(arr[i]);
    }

    cout<<inv;

    return 0;
}
