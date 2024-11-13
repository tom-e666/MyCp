#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll binpow(ll a, ll b,ll m)
{
	a%=m;
	ll res=1;
	while(b)
	{
		if(b&1)
		{
			res=res*a%m;
		}
		a=a*a%m;
		b>>=1;
	}
	return res;
}
ll binexpo(ll a, ll b)
{
	if(b==0) return 1;
	ll c=binexpo(a,b/2);
	c=c*c;
	if(b&1)
	{
		return c*a;
	}
	return c;
}
ll _fermat_pow(ll a, ll b,ll m,bool is_prime)
{

	if(is_prime)
	{
		b=b%(m-1);
		ll res=1;
		while(b)
		{
			res=res*a%m;
			b=b%(m-1);
		}
		return res;
	}else
	{
		ll res=1;
		while(b)
		{
			if(b&1)
			{
				res=res*a%m;
			}
			a=a*a%m;
			b>>=1;

		}
		return res;
	}

}
int main()
{
	cout<<binpow(2,8,7)<<"\n"<<_fermat_pow(2,8,7,true);
}