#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define db(x) clog << "[" #x " = " << x << " ]\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vector<int> v;
	int x;
	while (cin >> x)
	{
		v.emplace_back(x);
	}
	vector<int> a=v;
	sort(all(a));
	{
		// a
		auto p = a.end();
		if (p != a.begin())
		{
			p = prev(p);
			if (p != a.begin())
			{
				p = prev(p);
				int x = *p;
				cout << v.rend() - 1 - find(v.rbegin(), v.rend(), x) << "\n";
				db(v.rend() - 1 - find(v.rbegin(), v.rend(), x));
			}
			else
			{
				cout << "-1\n";
			}
		}
		else
		{
			cout << "-1\n";
		}
	}
	{
		// b;
		auto p = a.begin();
		while (p + 1 != a.end() && *p == *(p + 1))
			p++;
		if (p != a.end())
		{
			p++;
			if (p != a.end())
			{
				int n = v.size();
				for (int i = 0; i < n; ++i)
				{
					if (v[i] == *p)
					{
						cout << i << " ";
					}
				}
			}
			else
			{
				cout << "-1";
			}
		}
		else
		{
			cout << "-1";
		}
		cout << "\n";
	}
	{
		for (auto &i : a)
		{
			i = abs(i);
		}
		// c
		auto ucln = [](int x, int y) -> int
		{
			x = abs(x);
			y = abs(y);
			int z;
			while (y != 0)
			{
				z = x % y;
				x = y;
				y = z;
			}
			return x;
		};
		int tm = INT_MIN;
		for (int i = a.size()-1; i >= 0; i--)
		{
			int j = i - 1;
			while (j >= 0)
			{
				if (a[j] <= tm)
					break;
				tm = max(tm, ucln(a[i], a[j]));
				j--;
			}
		}
		if (tm != INT_MIN)
		{
			cout << tm << "\n";
		}
		else
		{
			cout << "-1\n";
		}
		db(ucln(7,7));
	}
	{
		// d
		// a is changed
		auto isE = [](int x) -> bool
		{
			if (x < 2)
				return false;
			for (int i = 2; i <= sqrt(x); ++i)
			{
				if (x % i == 0)
					return false;
			}
			return true;
		};
		int n = v.size();
		int ans = INT_MAX;
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j)
			{
				if (isE(v[i] + v[j]))
				{
					ans = min(ans, v[i] + v[j]);
				}
			}
		if (ans == INT_MIN)
		{
			cout << "-1";
		}
		else
		{
			cout << ans;
		}
	}
}