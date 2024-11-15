#include <bits/stdc++.h>
using namespace std;
#define loop(i, a, b) for (int i = a; i < b; ++i)
#define ll long long
const int INF = INT_MIN;
int n;
int main() {
    cin >> n;
    int a[n + 1][4];

    // Input matrix
    loop(i, 0, 4)
    loop(j, 1, n + 1) {
        cin >> a[j][i];
    }

    // DP table: dp[j][m] stores max sum for first `j` columns with mask `m`
    int dp[n + 1][1 << 4];
    loop(i, 0, n + 1) fill(dp[i], dp[i] + (1 << 4), INF);
    loop(i,0,1<<4)
    	dp[0][i]=0;
    // Precompute sums for all masks
    int mask_sum[1 << 4];
    loop(m, 0, 1 << 4) {
        int sum = 0;
        loop(mm, 0, 4) {
            if (m & (1 << mm)) {
                sum += a[1][mm];
            }
        }
        mask_sum[m] = sum;
    }

    // Fill DP table
    loop(j, 1, n + 1) {
        loop(m, 0, 1 << 4) { // Iterate over all masks
            int current_sum = 0;
            loop(mm, 0, 4) {
                if (m & (1 << mm)) {
                    current_sum += a[j][mm];
                }
            }
            loop(m_prev, 0, 1 << 4) { 
                // Check if masks m and m_prev are compatible
                if (m & m_prev == 0) {
                    dp[j][m] = max(dp[j][m], dp[j - 1][m_prev] + current_sum);
                }
            }
        }
    }

    // Find the maximum result in the last column
    int res = INF;
    loop(m, 0, 1 << 4) {
        res = max(res, dp[n][m]);
    }
    cout << res << "\n";
    loop(j,0,1<<4)
    cerr<<dp[1][j]<<" ";
    return 0;

}

