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
	ios_base::sync_with_stdio(0);
	string a,b;
	cin>>a>>b;
	int sz=max(a.size(),b.size());
	int dp[sz+1][sz+1];
	// dp[0][0]=0;
	// dp[0][1]=0;
	// dp[1][0]=0;
	// iota(dp[0],dp[0]+sz+1,0);
	loop(j,0,sz+1)
	{
		dp[0][j]=j;
		dp[j][0]=j;
	}
	// dp[1][1]=(a[0]==b[0]?0:1);
	loop(i,1,a.size()+1)
	loop(j,1,b.size()+1)
	{
		int x=i-1;
		int y=j-1;
		if(a[x]==b[y])
		{
			dp[i][j]=dp[i-1][j-1];
		}else
		{
			dp[i][j]=min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]))+1;
		}

	}
	cout<<dp[a.size()][b.size()];
	cerr<<dp[2][0];
}
