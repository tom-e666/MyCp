#include <bits/stdc++.h>
using namespace std;
const int limit = 4 * 1e6 + 2;
vector<bool> is_ele(limit, true);
bool is_elemental(int x)
{
	if (is_ele[0])
	{
		is_ele[0] = false;
		is_ele[1] = false;
		int lt = sqrt(limit);
		for (int i = 2; i <= lt; ++i)
		{
			if (is_ele[i])
			{
				for (int j = i; j < limit; j += i)
				{
					is_ele[j] = false;
				}
			}
		}
	}
	return is_ele[x];
}
bool is_dual_elemental(int x)
{
	if (!is_elemental(x))
		return false;
	int s = 0;
	while (x)
	{
		s += x % 10;
		x /= 10;
	}
	return is_elemental(s);
}

int main()
{
	int l, r;
	cin >> l >> r;
	is_elemental(0);
	int cnt = 0;
	for (; l <= r; ++l)
	{
		if (is_dual_elemental(l))
		{
			cnt++;
		}
	}
	cout << cnt;
}