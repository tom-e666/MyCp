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
int main()
{
	int n,x;
	cin>>n>>x;
	int c[n];
	loop(i,0,n) cin>>c[i];
	
	sort(c,c+n);
	int dp[x+1];
	fill(dp,dp+x+1,0);
	dp[0]=1;
	loop(ic,0,n)
	loop(s,c[ic],x+1)
	{
		dp[s]+=dp[s-c[ic]];
		dp[s]%=mod;
	}
	cout<<dp[x];
}