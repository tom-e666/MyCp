#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	int x;
	for (auto &i : v)
	{
		cin >> x;
		i = x % k;
	}

	vector<vector<int>> dp(n, vector<int>(k, 0));
	dp[0][v[0]] = 1;
	for (int i = 1; i < n; ++i)
	{
		int x = v[i];
		for (int j = 0; j < k; ++j)
		{	
			if(dp[i-1][(j  + x) % k])
			dp[i][(j  + x) % k] = max(dp[i][(j + x) % k], max(dp[i - 1][(j + x) % k], dp[i - 1][j] + 1));
		}
	}
	for (auto i : dp)
	{
		for (auto j : i)
			cout << j << " ";
		cout << endl;
	}
}