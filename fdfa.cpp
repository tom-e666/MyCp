#include <bits/stdc++.h>
using namespace std;
// int main()
// {
//     string a, b;
//     cin >> a >> b;
//     vector<vector<int>> dp(a.size()+1, vector<int>(b.size()+1, 0));
//     int na = a.size();
//     int nb = b.size();
//     for (int i = 1; i <= na; ++i)
//         for (int j = 1; j <= nb; j++)
//         {
//             if (a[i-1] == b[j-1])
//             {
//                 dp[i][j] = 1 + dp[i - 1][j - 1];
//             }
//             else
//             {
//                 dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//             }
//         }
//     cout << dp[na][nb];
// }

// tối ưu hóa bằng 2 mảng 1 chiều, mảng a[i] chứa giá trị tối ưu tại vị trí i?