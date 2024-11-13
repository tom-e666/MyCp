#include <bits/stdc++.h>
#define ull long long
#define all(x) begin(x), end(x)
#define fast                      \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);                   \
	cout.tie(0);
using namespace std;
ull m, n, A, B, C;
ull ans = INT_MAX;
vector<vector<ull>> v;
int main()
{
	fast;
	cin >> m >> n >> A >> B;
	C = (A + B) / 2;
	v = vector<vector<ull>>(m, vector<ull>(n));
	for (auto &a : v)
		for (auto &b : a)
			cin >> b;
	decltype(v) cn = vector<vector<ull>>(m, vector<ull>(n, 0));
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
		{
			if (i == 0 && j == 0)
			{
				cn[i][j] = v[i][j];
			}
			else if (i == 0)
			{
				cn[i][j] = cn[i][j - 1] + v[i][j];
			}
			else if (j == 0)
			{
				cn[i][j] = cn[i - 1][j] + v[i][j];
			}
			else
			{
				cn[i][j] = cn[i - 1][j] + cn[i][j - 1] - cn[i - 1][j - 1] + v[i][j];
			}
		}
	ull t;
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
		{
			bool flag = false;
			for (int a = i; a < m; ++a)
			{
				for (int b = j; b < n; ++b)
				{

					if (i == 0 && j == 0)
						t = cn[a][b];
					else if (i == 0)
					{
						t = cn[a][b] + -cn[a][j - 1];
					}
					else if (j == 0)
					{
						t = cn[a][b] - cn[i - 1][b];
					}
					else
					{
						t = cn[a][b] + cn[i - 1][j - 1] - cn[a][j - 1] - cn[i - 1][b];
					}
					ans = min(ans, abs(t - A) + abs(t - B));
					if (t > C)
					{
						flag = true;
						break;
					}
					if (flag)
					{
						break;
					}
				}
			}
		}
	cout << ans;
}