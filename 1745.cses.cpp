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
	int c[n];
	int s=0;
	loop(i,0,n)
	{
	 cin>>c[i];
	 s+=c[i];
	}
	sort(c,c+n);
	bool dp[s+1];
	fill(dp,dp+s+1,false);
	dp[s]=true;
	loop(ic,0,n)
	{
		loop(is,1,s-c[ic]+1)
		{
			dp[is]|=dp[is+c[ic]];
		}
	}
	stringstream ss;
	int cnt=0;
	loop(i,1,s+1)
	{
		if(dp[i])
		{
			cnt++;
			ss<<i<<" ";
		}
	}
	cout<<cnt<<"\n"<<ss.str();


}