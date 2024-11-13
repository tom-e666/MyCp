#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
struct fenwick{
	vi bit;
	fenwick(int n)
	{
		bit.resize(n,0);
	}
	fenwick(const vi& v)
	{
		bit.resize(v.size());
		for(int i=0;i<v.size();++i)
		{
			add(i,v[i]);
		}
	}
	int sum(int r)
	{
		int res=0;
		for(;r>-1;r=r&(r+1)-1)
			res+=bit[r];
		return res;
	}
	int sum(int l, int r)
	{
		return sum(r)-sum(l-1);
	}
	void add(int i, int val)
	{
		for(;i>-1;i=i&(i+1))
			{
				bit[i]+=val;
			}
	}

};
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}