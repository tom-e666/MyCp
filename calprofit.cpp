#include<bits/stdc++.h>
typedef long long ll;
#define vl vector<ll>
using namespace std;
ll n,m;
vl rate,w;
ll res=0;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	rate.resize(n,0);
	w.resize(m,0);
	for(int i=0;i<n;++i)
		cin>>rate[i];
	for(int i=0;i<m;++i)
		cin>>w[i];
	queue<ll> qu;
	set<ll> s;
	ll mem[3000];
	memset(mem,0,sizeof(mem));
	for(int i=0;i<n;++i)
		s.insert(i);
	ll x;
	m<<=1;
	for(int i=0;i<m;++i)
	{
		cin>>x;
		if(x>0)
		{
			if(s.empty()){
				qu.push(x);
			}else
			{
				auto lot=*s.begin();
				res+=rate[lot]*w[x-1];
				mem[x]=lot;
				s.erase(s.find(lot));
			}
		}else
		{
			auto lot=mem[-x];
			if(!qu.empty()){
				auto j=qu.front();
				qu.pop();
				res+=rate[lot]*w[j-1];
				mem[j]=lot;
				mem[-x]=0;
			}else{
				mem[-x]=0;
				s.insert(lot);
			}
		}
	}
	cout<<res;
	

}