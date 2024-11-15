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
signed main()
{
	int n;
	cin>>n;
	int dp[n+1];
	dp[0]=0;
	fill(dp+1,dp+n+1,INT_MAX-10);
	loop(i,1,n+1)
	{
		int t=i;
		while(t)
		{
			if(int c=t%10;i>=c)
			dp[i]=min(dp[i],dp[i-c]+1);
			t/=10;
		}
	}
	cout<<dp[n];
	cerr<<dp[9];
	}