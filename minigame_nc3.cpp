#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >> n >> k;
	vector<string> v(n);
	for (auto &s : v)
		cin >> s;
	vector<string> dp(k + 1, string(k + 1, 'z'));
	dp[0] = "";
	for (auto s : v)
	{
		int sz = s.size();
		for (int j = k - sz; j >= 0; --j)
		{
			dp[j + sz] = min(dp[j + sz], dp[j] + s);
		}
	}
	cout << dp[k] << "\n";
	return 0;
}