#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define loop(i,a,b) for(int i=a;i<b;++i)
#define ll long long
#define F first
#define S second
#define pii pair<int,int>
#define vi vector<int>
#define vl vector<long long>bool v[9][9];
const int inf=1e9+1;
int n,x;
int get(int x,int *c,int *dp)
{
	if(dp[x]!=0) return dp[x];
	int res=inf;
	loop(i,0,n)
	{
		if(x-c[i]>=0)
		{
			res=min(res,get(x-c[i],c,dp)+1);
		}
	}
	return dp[x]=res;
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n,x;
	cin>>n>>x;
	int c[n];
	loop(i,0,n) cin>>c[i];
	int dp[1000001];
	fill(dp,dp+1000001,0);
	int t=get(x,c,dp);
	if(t==inf)
	{
		cout<<"-1";
	}else
	{
		cout<<t;
	}

}