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
	char c;
	int mp[n+1][n+1];

	// loop(i,1,n+1)
	// {
	// 	mp[i][1]=1;
	// 	mp[1][i]=1;
	// }
	loop(i,1,n+1)
	loop(j,1,n+1)
	{
		cin>>c;
		if(c=='*')	
		{
			mp[i][j]=0;
		}else
		{
			mp[i][j]=1;
		}
	}
	loop(i,2,n+1)
	{
		mp[i][1]&=mp[i-1][1];
		mp[1][i]&=mp[1][i-1];
	}
	loop(i,2,n+1)
	loop(j,2,n+1)
	{

		if(mp[i][j]==0) continue;
		mp[i][j]=mp[i-1][j]+mp[i][j-1];
		mp[i][j]%=mod;
	}
	cout<<mp[n][n];
	

}
