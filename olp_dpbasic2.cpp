#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    // Initialize the DP table
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));
    dp[0][0] = 0;

    // Sort the dishes in decreasing order of cooking time
    sort(v.begin(), v.end(), greater<int>());

    // Update the DP table
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            if (i + j > n)
                continue;
            if (i > 0)
                dp[i][j] = min(dp[i][j], max(dp[i - 1][j], v[i + j - 1]));
            if (j > 0)
                dp[i][j] = min(dp[i][j], max(dp[i][j - 1], v[i + j - 1]));
        }
    }

    // Find the minimum total time
    int res = INT_MAX;
    for (int i = 0; i <= n; ++i)
    {
        res = min(res, dp[i][n - i]);
    }

    cout << res << endl;
    return 0;
}