#include<bits/stdc++.h>
#define ll long long
#define db(x) cerr<<#x<<" : "<<x
using namespace std;
int getlead(ll n, ll k)
{
	double fl=(double)log10(n)*k;
	fl=fl-floor(fl);
	return floor(pow(10,fl)*100);
}
string gettrail(ll n, ll k )
{
	int mod=1000;
	n%=mod;
	ll res=1;
	while(k)
	{
		if(k&1)
		{
			res=res*n%mod;
		}
		n=n*n%mod;
		k>>=1;
	}
	string s=to_string(res);
	return string(3-s.size(),'0')+s;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll t;
	cin>>t;
	ll n,k;
	while(t--)
	{
		cin>>n>>k;
		cout<<getlead(n,k);
		cout<<"...";
		cout<<gettrail(n,k);
		cout<<"\n";
	}
}