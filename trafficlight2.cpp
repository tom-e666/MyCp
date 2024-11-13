#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
int x, n;
vector<int> prl; // previous node of n[1] .. x (n)
vector<int> prr; // next node of n[0] .. n[n-1] (n)
int find_pr(int x, vector<int> &pr)
{
	if (x == 0)
		return 0;
	if (x == n + 1)
		return n + 1;
	if (x == pr[x])
	{
		return x;
	}
	pr[x] = find_pr(pr[x], pr);
	return pr[x];
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> x >> n;
	vector<int> v(n);
	for (auto &i : v)
		cin >> i;

	vector<int> vv(all(v));
	vv.emplace_back(x);
	vv.emplace_back(0);
	sort(all(vv));
	prl = vector<int>(n + 1);
	for (int i = 1; i < n + 1; ++i)
	{
		prl[i] = i;
	}
	prl[0] = 0;
	prr = vector<int>(n + 1);
	for (int i = 0; i < n; ++i)
	{
		prr[i] = i;
	}
	prr[n] = n;
	int m = vv[1];
	for (int i = 1; i < n + 2; ++i)
	{
		m = max(m, vv[i] - vv[i - 1]);
	}
	vector<int> ans{m};
	vector<int> rv(rbegin(v), rend(v));
	for (auto b : rv)
	{
		auto aa = find(all(vv), b);
		if (aa == vv.begin() || aa == vv.end())
		{
			ans.emplace_back(ans[ans.size() - 1]);
		}
		else
		{
			int a = aa - vv.begin();
			prl[a] = a - 1;
			prr[a] = a + 1;
			int l = find_pr(a, prl);
			int r = find_pr(a, prr);
			m = max(m, vv[r] - vv[l]);
			ans.emplace_back(m);
		}
	}
	ans.erase(ans.end() - 1);
	reverse(all(ans));
	for (auto i : ans)
		cout << i << " ";
}