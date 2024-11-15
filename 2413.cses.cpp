#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define loop(i, a, b) for (int i = a; i < b; ++i)
#define ll long long
#define F first
#define S second
#define pii pair<int, int>
#define vi vector<int>
const int mod=1e9+7;
int n,m;
signed main()
{
	
	int t;
	cin>>t;
	int a[t];
	int m=INT_MIN;
	loop(i,0,t)
	{
		cin>>a[i];
		m=max(m,a[i]);
	}
	ll dp[m+1][2];
	dp[1][0]=1;
	dp[1][1]=1;
	loop(h,2,m+1)
	{
		//0 no vertical slash
		//1 have vertical slash
		dp[h][0]=dp[h-1][0]*2+dp[h-1][1];
		dp[h][0]%=mod;
		dp[h][1]=dp[h-1][0]+dp[h-1][1]*4;
		dp[h][1]%=mod;
	}
	loop(i,0,t)
	{
		cout<<(dp[a[i]][0]+dp[a[i]][1])%mod<<"\n";
	}
	cerr<<dp[2][0]<<" "<<dp[2][1];



}