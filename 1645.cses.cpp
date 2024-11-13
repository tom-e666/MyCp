//range count
//idea:  [a,b] sort a: <, b: >
// query 1: query by set , after remove it
// query 2: query by set, after remove, from right to left
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db(x) cerr<<#x<<" : "<<x<<"\n";
struct range{
	ll l,r,idx,contain, contained;
	bool operator <(const range & o) const
	{
		if(l==o.l) return r>o.r;
		return l<o.l;
	}
};
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin>>n;
	range arr[n];
	ll l ,r;
	multiset<ll> a;
	for(int i=0;i<n;++i)
		{
			cin>>l>>r;
			arr[i]	=range({l,r,i,0,0});
			a.insert(r);
		}
	sort(arr,arr+n);
	{
		for(int i=0;i<n;++i)
		{
			auto it=s.upper_bound(arr[i].r);
			if(it==s.begin())
			{
				
			}else
			{
				arr[i].contain=distance(it,s.begin())-2;
			}
			
		}
	}
	




}

