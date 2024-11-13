#include<bits/stdc++.h>
#define ll long long
#define vll vector<vector<long long>>





using namespace std;
ll n, l,m;
vector<ll> entry,tran,ext;
const ll mod=1e9+7;
vll makeMT()
{
	vll a(m,vector<ll>(m,0));
	for(int i=0;i<m;++i)
		for(int j=0;j<m;++j)
            a[i][(tran[j]+i)%m]=1;
	return a;
}
vll mult(vll a, vll b)
{
	vll c(m,vector<ll>(m,0));
	for(int i=0;i<m;++i)
		for(int j=0;j<m;++j)
		{
			c[i][j]=0;
			for(int q=0;q<m;++q)
			{
				c[i][j]+=a[i][q]*b[q][j];
				c[i][j]%=mod;
			}

		}
	return c;
}
vll expo(vll base, ll n)
{
	vll res(m,vector<ll>(m,0));
	for(int i=0;i<m;++i)
		res[i][i]=1;
	while(n)
	{
		if(n&1)
		{
			res= mult(res,base);
		}
		base=mult(base,base);
		n>>=1;
	}
	return res;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>l>>m;
	
	entry.resize(n);
	ext.resize(n);
	tran.resize(n);
	for(int i=0;i<n;++i)
		cin>>entry[i];
	for(int i=0;i<n;++i)
		cin>>tran[i];
	for(int i=0;i<n;++i)
		cin>>ext[i];
	vll base=makeMT();
	vll rebase=expo(base,l-2);
	ll res = 0;
for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
    	ll a=entry[i]%m;
    	ll b=ext[j]%m;
    	ll t=(m-a+m-b+m-tran[j])%m;
     	res+=rebase[a][t];
    }
}
cout<<res;
	for(int i=0;i<m;++i){
		for(int j=0;j<m;++j)
			cerr<<rebase[i][j]<<" ";
		cerr<<"\n";
	}
}