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
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	int a[n], b[n], c[n];

	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < n; i++)
		cin >> b[i];

	for (int i = 0; i < n; i++)
		c[i] = a[i] - b[i];

	pbds t;
	long long int ans = 0;

	for (int i = 0; i < n; i++)
	{
		ans += t.size() - t.order_of_key({-c[i], 1000000});
		t.insert({c[i], i});
	}

	cout << ans;

	return 0;
}