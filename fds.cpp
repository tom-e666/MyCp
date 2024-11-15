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
			while (trash < n && x[trash] <= r[i] + t) trash++;
		}
	}
	if (trash == n) return true;
	return false;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cout << "hi";
}
