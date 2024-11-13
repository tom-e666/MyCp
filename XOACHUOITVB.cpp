//dynamic programming
#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	int x,y;
	cin>>s>>x>>y;
	long long res=0;
	vector<long long> dp(s.sizse(),0);
	if(s.size()<2) 
	{
		cout<<0;
		return 0;
	}
	string t= s.sub_str(0,2);
	char last;
	if(t=="bn")
	{
		dp[1]=x;
	}
	if(t=="nb")
	{
		dp[1]=y;
	}
	for(int i=2;i<n;++i)
	{
		dp[i]=dp[i-1];
		auto t=s.sub_str(i-1,2);
		if(t=='bn')
		{
			dp[i]=max(dp[i],x+dp[i-2]);

		}
		else if(t='nb')
		{
			dp[i]=max(dp[i],y+dp[i-2]);
		}
	}
	cout<<

}