#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define vi vector<int>
using namespace std;
int m, n;
vi r, x;
bool Try(int t)
{
	//greedy left;
	int trash = 0;
	for (int i = 0;i < m;++i)
	{
		if (trash == n) return true;
		if (x[trash] < r[i])
		{
			if (x[trash] < r[i] - t) return false;
			int rr = max(r[i], r[i] + t - 2 * (r[i] - x[trash]));
			while (trash < n && x[trash] <= rr) trash++;
		}
		else
		{
			while (trash < n&& x[trash] <= r[i] + t) trash++;
		}
	}
	if (trash == n) return true;
	return false;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> m >> n;
	vector<int> r(m), x(n);//robot, rac
	for (auto& i : r) cin >> i;

	for (auto& i : x) cin >> i;
	sort(r.begin(), r.end());
	sort(x.begin(), x.end());
	//false....true
	int t = 0;
	for (int p = max(m, n);p > 0;p /= 2)
	{
		while (!Try(t + p)) t += p;
	}
	cout << t + 1;

}
