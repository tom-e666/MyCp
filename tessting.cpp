#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int l, r;
	cin >> l >> r;
	if (l % 2 == 1)
		l++;
	if (r % 2 == 1)
		r--;
	if (l >= r)
	{
		cout << "0";
		return;
	}
	// s= amount*sum/2= (sub/2+1)*sum/2
	cout << ((r - l) / 2 + 1) * (l + r) / 2;
	return 0;
}