#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    pbds st;
    //value,index pair
    st.insert({34, 1});
    st.insert({34, 3});
    st.insert({35, 2});
    st.insert({3, 4});

    for (int i = 0; i < st.size(); i++)
    {
        cout << i << " " << st.find_by_order(i)->first << " " << st.find_by_order(i)->second << "\n";
    }

    // cout << " " << st.order_of_key(5) << "\n";

    return 0;
}
