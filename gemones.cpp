#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,k;
const long long mod=1e9+7;
int cv( char x)
{
	if(x>='a')
		return x-'a';
	else return x-'A'+26;
}
ll imult(ll a, ll b)
{
	ll res=0;
	while(b)
	{
		if(b&1)
		{
			res=(res+a)%mod;
		}
		b>>=1;
		a=(a+a)%mod;

	}
	return res;
}
vector<vector<ll>> mult(vector<vector<ll>> a, vector<vector<ll>>b)
{
	vector<vector<ll>>res(m,vector<ll>(m));
	for(int i=0;i<m;++i)
		for(int j=0;j<m;++j)
		{
			res[i][j]=0;
			for(int x=0;x<m;++x)
			{
				res[i][j]=(res[i][j]+a[i][x]*b[x][j])%mod;
			}
		}
	return res;
}
vector<vector<ll>> xpow(vector<vector<ll>>mt, ll n)
{
	vector<vector<ll>>res(m, vector<ll>(m,0));
	for(int i=0;i<m;++i) res[i][i]=1;
	while(n)
	{
		if(n&1)
		{
			res=mult(res,mt);
		}
		n>>=1;
		mt=mult(mt,mt);
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>m>>k;
	vector<vector<long long>> mt(m,vector<long long>(m,1));

	char x, y;
	for(int i=0;i<k;++i)
	{
		cin>>x>>y;
		mt[cv(x)][cv(y)]=0;
	}


	ll res=0;
	mt = xpow(mt,n-1);
	
	for(int i=0;i<m;++i)
		for(int j=0;j<m;++j)
			res=(res+mt[i][j])%mod;
	cout<<res;

};

