#include<bits/stdc++.h>
using namespace std;
#define Int uint64_t
Int Imult(Int a,Int b, Int m)
{
	Int res=0;
	while(b)
	{
		if(b&1)
		{
			res=(res+a)%m;
		}
		b>>=1;
		a=(a+a)%m;
	}
	return res;
}
Int binpow(Int base, Int exp, Int mod)
{
	Int res=1;
	while(exp)
	{
		if(exp&1)
		{
			res=Imult(res,base,mod);
		}
		base=Imult(base,base,mod);
		exp>>=1;
	}
	return res;
}
uint64_t binpow(uint64_t base, uint64_t exp, uint64_t mod)
{
	uint64_t res=1;
	while(exp)
	{
		if(exp&1)
		{
			res=Imult(res,base,mod);
		}
		base=Imult(base,base,mod);
		exp>>=1;
	}
	return res;

}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	Int c,a,b,m;
	cin>>c;
	while(c--)
	{
		cin>>a>>b>>m;
		cout<<binpow(a,b,m)<<'\n';
	}
}
