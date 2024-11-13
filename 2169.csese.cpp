#include<bits/stdc++.h>
#define db(x) cerr<<#x<<" : "<<x<<"\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
using namespace std;
struct range
{
	ll a,b,idx;
	bool operator < (const range & o) const
	{
		if(a==o.a) return b>o.b;
		return a<o.a;
	}
	
};
int main()
{
	//nested range count
	//idea::sliding window, find index 
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	ll  n;
	cin>>n;
	range arr[n];
	multiset<ll> s;
	for(int i=0;i<n;++i)
	{
		cin>>arr[i].a>>arr[i].b;
		arr[i].idx=i;
		s.insert(arr[i].b);
	}	
	ll contain[n];
	ll contained[n];
	sort(arr,arr+n);
	{
multiset<ll> ss(s.begin(),s.end());	
	for(int i=0;i<n;++i)
		{
			//find idx
			ll v= distance(ss.begin(),upper_bound(all(ss),arr[i].b))-1;
			contain[arr[i].idx]=v;
			ss.erase(ss.find(arr[i].b));
		}
 
	}
	{
multiset<ll> ss(s.begin(),s.end());	
	for(int i=n-1;i>-1;--i)
		{
			//find idx
			ll v= distance(lower_bound(all(ss),arr[i].b),ss.end())-1;
			contained[arr[i].idx]=v;
			ss.erase(ss.find(arr[i].b));
		}
 
	}
	for(int i=0;i<n;++i) cout<<contain[i]<<" ";
	cout<<"\n";
	for(int i=0;i<n;++i) cout<<contained[i]<<" ";
}
 
	
 
 
 
 
