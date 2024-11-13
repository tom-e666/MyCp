#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, a;
	cin >> n >> a;
	vector<vector<int>> v(n + 1, vector<int>(n + 1));
	for (int i = n; i > 0; --i)
		for (int j = n; j > 0; --j)
		{
			v[i][j] = a++;
		}
	{
		for (int j = 2; j <= n; j += 2)
		{
			for (int i = 1; i <= n; ++i)
				cout << v[i][j] << " ";
			cout<<"\n";
		}

	}
	{
		int j=n;
		int a = INT_MAX;
		for (int i = 1; i <= n; ++i)
		{
			if (v[i][j]  % 2== 1)
			{
				a = min(a, v[i][j]);
			}
			clog<<v[i][j]<<" ";
		}
		if (a != INT_MAX)
		{
			cout << a << "\n";
		}
		else
		{
			cout << "NULL\n";
		}
	}
	{
		vector<int> dx{1, 1, n, n};
		vector<int> dy{1, n, 1, n};
		int s = 0;
		for (int i = 0; i < 4; ++i)
		{
			if (v[dx[i]][dy[i]] % 2 == 0)
				s += v[dx[i]][dy[i]];
		}
		cout << s;
	}
}