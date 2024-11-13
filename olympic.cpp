// oympic solution: pppppppqqqq
#include <bits/stdc++.h>
using namespace std;
int m, n, p, q, k;
void fn()
{
	cin>>m>>n>>p>>q>>k;
	int p_per = k / p;
	int p_doer = ceil(1.0*m / p_per);
	int spill = m - p_per * (p_doer - 1);
	int excess = k - spill * p;
	
	n -= excess / q;
	int q_per = k / q;
	int q_doer = ceil(1.0*n / q_per);
	cout << p_doer+q_doer<<"\n";
	
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		fn();
	}
}