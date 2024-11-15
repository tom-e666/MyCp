#include <bits/stdc++.h>
using namespace std;
#define loop(i, a, b) for (int i = a; i < b; ++i)
#define ll long long
const int mod = 1e9+7;

void solve() {
    int n, k;
    cin >> n >> k;

    int max_mask = (1 << n); // Maximum bitmask (2^n)
    ll dp[max_mask][n];     // DP table for masks and positions
    memset(dp, 0, sizeof(dp)); // Initialize DP array to 0

    // Base case: Single element sequences
    loop(j, 0, n) dp[1 << j][j] = 1;

    // Fill DP table
    loop(mask, 0, max_mask) {       // Iterate over all masks
        loop(j, 0, n) {             // Iterate over current positions
            if (!(mask & (1 << j))) continue; // Skip if j is not in the mask

            loop(m, 0, n) {         // Iterate over previous positions
                if ((mask & (1 << m)) && abs(m - j) <= k) { // Valid transition
                    dp[mask][j] = (dp[mask][j] + dp[mask ^ (1 << j)][m]);
                }
            }
        }
    }

    // Compute result
    ll res = 0;
    int full_mask = max_mask - 1; // All elements included
    loop(j, 0, n) {
        res = (res + dp[full_mask][j]);
    }

    cout << res << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
