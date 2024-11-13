/*i j< k
v[k] oke, iterate ij[k]
ij[K?]= max(i-1,i-1,j-1);

1
11
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	ll n;
	cin >> n;
	vector<ll> v(n),dp2(n), dpl(n), dpr(n);
	for (auto &i : v)
		cin >> i;
	dp2[0] = INT_MIN;
	dp2[1] = v[0] + 2 * v[1];
	dpr[n - 1] =v[n - 1];
	dpl[0]=v[0];

	for(int i=1;i<n;++i){
		dpl[i]=max(dpl[i-1],v[i]);
	}
	for (int i = n - 2; i >= 0; --i)
	{
		dpr[i] = max(dpr[i + 1],v[i]);
	}
	for (int i = 2; i < n; ++i) // max  at m,n<=i
	{
		dp2[i] =max(dp2[i-1],dpl[i-1]+2*v[i]);
	}
	ll res = INT_MIN;
	for (int i = 1; i < n-1; ++i)
	{
		res = max(res, dp2[i] + 3*dpr[i+1]);
	}
	cout << res;
	for(auto i: dp2) cerr<<i<<"\n";
}