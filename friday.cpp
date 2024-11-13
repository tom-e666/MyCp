#include<bits/stdc++.h>
using namespace std;
vector<int> v;
void c_sort( vector<int> & v)
{
	int l=v[0];
	int r=v[0];
	for(int i=1;i<v.size();++i) 
	{
		l=min(v[i],l);
		r=max(v[i],r);
	}
	vector<int>cc(r-l+1,0);
	for(int i=0;i<v.size();++i)
	{
		cc[v[i]-l]++;
	}
	for(int i=1;i<cc.size();++i)
	{
		cc[i]+=cc[i-1];
	}
	vector<int> res(v.size());
	for(int i=v.size()-1;i>-1;--i)
	{
		res[--cc[v[i]-l]]=v[i];
	}
	v=res;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int x;
	while(cin>> x) v.push_back(x);
		for(auto i: v) cout<<i<<" ";
			cout<<"\n";
	c_sort(v);
	for(auto i: v) cout<<i<<" ";

	
}
