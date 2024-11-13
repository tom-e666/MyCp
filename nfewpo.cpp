#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
struct FenWick{
	vi bit;
	FenWick(int n)
	{
		bit.resize(n,0);
	}
	FenWick(vi v)
	{
			bit.resize(v.size(),0);
			for(int i=0;i<v.size();++i)
			{
				bit[i]+=v[i];
				int r=i|(i+1);
				if(r<v.size()) bit[r]+=bit[i];
			}
	}
	void add(int i, int va)
	{
		for(;i<bit.size();i=i|(i+1))
			bit[i]+=va;
	}
	int sum(int r)
	{
		int res=0;
		for(;r>-1;r=r&(r+1)-1)
			res+=bit[r];
		return res;
	}
	int sum (int l , int r)
	{
		return (l==0?sum(r):sum(r)-sum(l-1));
	}
};
struct FenMin{
vi bit;
const int INF=1e9;
FenMin(int n)
{
	bit.resize(n,INF);
}
FenMin(vi v)
{
	bit.resize(v.size(),INF);
	for(int i=0;i<v.size();++i)
	{
		update(i,v[i]);
	}
}
void update(int i, int val)
{
	for(;i<bit.size();i=i|(i+1))
		bit[i]=min(bit[i],val);
}
int getmin(int r)
{
	int res=INF;
	for(;r>-1;r=(r&(r+1)-1))
		res=min(res,bit[r]);
	return res;
}
};

int main()
{
	string s="a,bc/";
	cout<<s.substr(0,s.find('/'));
	cerr<<s.find('/');

}