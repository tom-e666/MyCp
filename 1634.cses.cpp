#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define loop(i, a, b) for (int i = a; i < b; ++i)
#define ll long long
#define F first
#define S second
#define pii pair<int, int>
#define vi vector<int>
signed main()
{
	int n,x;
	cin>>n>>x;
	int c[n];
	loop(i,0,n) cin>>c[i];
	int dp[x+1];
	fill(dp,dp+x+1,INT_MAX-1);

	dp[0]=0;
	loop(s,1,x+1)
	{
		loop(j,0,n)
		{
			if(s>=c[j] && dp[s]>dp[s-c[j]]+1) dp[s]=dp[s-c[j]]+1;
		}
	}
	cout<<(dp[x]==INT_MAX-1?-1:dp[x]);


}