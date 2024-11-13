#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int mod=1e9+7;
	int n,m;
	cin>>n>>m;
	vector<vector<int>>dp(1<<n,vector<int>(n+1,0));
	dp[1][1]=1;
	vector<vector<int>>start(n+1);
	int x,y;
	for(int i=0;i<m;++i)
	{
		cin>>x>>y;
		start[y].emplace_back(x);
	}
	for(int s=2;s<1<<n;++s)
	{
		if(!(s&1)) continue;
		if((s&1<<(n-1))&&(s!=(1<<n)-1)) continue;
		for(int end=1;end<=n;++end){
			if(!(s&1<<(end-1))) continue;
			int ns=s-(1<<(end-1));
		for(const auto &st:start[end])		
		{
			dp[s][end]+=dp[ns][st];
			dp[s][end]%=mod;
		}
	}
}
cout<<dp[(1<<n)-1][n];



}