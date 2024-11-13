#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;
ll mult(ll a, ll b)
{
	ll res=0;
	while(b)
	{
		if(b&1)
		{
			res=(res+a)%mod;
		}
		b>>=1;
		a=a*2%mod;
	}
	return res;
}

ll npow(ll base, ll exp)
{
	base%=mod;
	ll res=1;
	while(exp)
	{
		if(exp&1)
		{
			res=mult(res,base);
		}
		exp>>=1;
		base=mult(base,base);
	}
	return res;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	cin>>n;
	ll even=(n-1)/2+1;
	ll odd=n-even;
	cout<< npow(5,even)*npow(4,odd)%mod;
	cerr<<npow(0,4);




}