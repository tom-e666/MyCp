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
	int a,b;
	cin>>a>>b;
	int dp[a+1][b+1];
	loop(i,0,min(a,b)+1)
		dp[i][i]=0;
	loop(i,1,a+1)
	loop(j,1,b+1)
	{
		if(i==j)
		{
			dp[i][j]=0;
		}
		else
		{
			dp[i][j]=INT_MAX;
			loop(n,1,j)
			{
				dp[i][j]=min(dp[i][j],dp[i][n]+dp[i][j-n]+1);
			}
			loop(n,1,i)
			{
				dp[i][j]=min(dp[i][j],dp[n][j]+dp[i-n][j]+1);
			}
		}
	}
	cout<<dp[a][b];



}