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
	int dp[x+1];
	dp[0]=1;
	loop(s,1,x+1)
	{
		dp[s]=0;
		loop(j,0,n)
		{
			if(s>=c[j])
			{
				dp[s]+=dp[s-c[j]];
				dp[s]%=mod;
			}
		}
	}

	cout<<dp[x];
	
}