#include <bits/stdc++.h>
using namespace std;
// a ~w c ~v
int main()
{
    int n, w;
    cin >> n >> w;
    vector<int> a(n + 1), c(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i] >> c[i];

    vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0)), track(n + 1, vector<int>(w + 1, 0));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= w; ++j)
        {
            int x = dp[i - 1][j];
            if (j - a[i] < 0)
            {
                dp[i][j] = x;
                track[i][j] = 0;
            }
            else
            {
                int y = dp[i - 1][j - a[i]] + c[i];
                if (x < y)
                {
                    dp[i][j] = y;
                    track[i][j] = 1;
                }
                else
                {
                    dp[i][j] = x;
                    track[i][j] = 0;
                }
            }
        }
    cout << dp[n][w] << "\n";
    int x = w;
    int cnt = n;
    stringstream ss;
    for (int i = 0; i < cnt; ++i)
    {
        ss << track[n][x] << " ";
        x -= track[n][x] * a[n];
        n--;
    }
    string s = ss.str();
    reverse(begin(s), end(s));
    cout << s;
}