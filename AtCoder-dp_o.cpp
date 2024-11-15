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
	int a[n][n];
	loop(i,0,n)
	loop(j,0,n)
		cin>>a[i][j];
	ll sz=1<<n;
	ll dp[sz][sz];
	loop(i,0,n)
	loop(j,0,n)
	{
		cin>>a[i][j];
		dp[1<<i][1<<j]=1;
	}
	loop(men,1,sz)
	{
		
	}

}