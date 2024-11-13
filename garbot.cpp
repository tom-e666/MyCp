#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) begin(x), end(x)
int m, n;
vector<int> r, x;
bool check(int t, int n)
{
	int xi = 0;
	for (int i = 0; i < m; ++i)
	{
		int rr = r[i];
		if (x[xi] < r[i])
		{
			if (r[i] - x[xi] > t)
			{ 
				return false;
			}
			else
			{
			    int m1= x[xi]+(t-(r[i]-x[xi]));// left->right
			    int m2= r[i]+(t-(r[i]-x[xi]))/2; //right->left
				rr=max(m1,m2);
			}
		}
		else
		{
			rr += t;
		}
		while (xi < n && x[xi] <= rr)
			xi++;
		if(xi==n) return true;
	}
	return xi == n;
}
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> m >> n;
	for (int i = 0; i < m; ++i)
	{
		int k;
		cin >> k;
		r.emplace_back(k);
	}
	for (int i = 0; i < n; ++i)
	{
		int k;
		cin >> k;
		x.emplace_back(k);
	}
	sort(all(r));
	sort(all(x));
	int a = 0;
	for (int p = n / 2; p > 0; p /= 2)
	{
		while (!check(a + p, n))
			a += p;
	}
	cout << a + 1;
}