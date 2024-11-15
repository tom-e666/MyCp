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
	
	cin>>n>>m;
	int a[n+1];
	loop(i,1,n+1) cin>>a[i];
	ll dp[n+1][m+2];

	loop(i,0,n+1) {
		dp[i][0]=0;
		dp[i][m+1]=0;
	}
	if(a[1]==0)
	{
		fill(dp[1]+1,dp[1]+m+1,1);

	}else
	{
		fill(dp[1]+1,dp[1]+m+1,0);
		dp[1][a[1]]=1;
	}
	loop(i,2,n+1)
	{
		if(a[i]==0)
		{
			loop(j,1,m+1)
			{
				dp[i][j]=dp[i-1][j-1]+dp[i-1][j]+dp[i-1][j+1];
				dp[i][j]%=mod;
			}
		}else
		{
			fill(dp[i],dp[i]+m+2,0);
			dp[i][a[i]]=dp[i-1][a[i]-1]+dp[i-1][a[i]]+dp[i-1][a[i]+1];
				dp[i][a[i]]%=mod;
		}
	}
	ll s=0;
	if(a[n]==0)
	{
		
		loop(j,1,m+1)
		{
			s+=dp[n][j];
			s%=mod;
		}
	}else
	{
		s=dp[n][a[n]];
	}
	cout<<s;
}