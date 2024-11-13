#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
typedef vector<ll> vl;
ll mile(vl v){
	ll res=0;
	for(auto i: v)
	{
		res+=ceil(1.0*++i/30)*10;
	}
	return res;
}
ll juice(vl v)
{
	ll res=0;
	for(auto i: v)
	{
		res+=ceil(1.0*++i/60)*15;
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	int i=1;
	while(t--)
	{
		int n;
		cin>>n;
		vl v(n,0);
		for(int i=0;i<n;cin>>v[i],++i);
        ll x = mile(v);
        ll y = juice(v);
        cout<<"Case "<<i++<<": ";
		if(x == y)
		{
			cout<< "Mile Juice "<<x<<'\n';
		}else if (x<y)
		{
			cout<<"Mile "<<x<<'\n';
		}else cout<<"Juice "<<y<<"\n";
		cerr<<x<<y<<"\n";
	}

}