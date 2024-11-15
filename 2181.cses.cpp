#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define loop(i, a, b) for (int i = a; i < b; ++i)
#define ll long long
#define F first
#define S second
#define pii pair<int, int>
#define vi vector<int>
const int mod=1e9+7;
int n,m;
//from curmask, gen list of mask
void getnext(vi &listmask, int curmask,int nextmask,int j)
{
	if(j==n)
	{
		listmask.push_back(nextmask);
		return;
	}
	if(j<n && (curmask&(1<<j))==0&& j+1<n&& (curmask&(1<<(j+1)))==0)
	{
		getnext(listmask,curmask,nextmask,j+2);
	}
	if(j<n && (curmask&(1<<j))==0)
	{
		getnext(listmask,curmask,nextmask|(1<<j),j+1);
	}
	if(j<n && (curmask&(1<<j))!=0)
	{
		getnext(listmask,curmask,nextmask,j+1);
	}
}
map<pii,ll>mp;
ll count(int i, int curmask)
{
	if(mp[{i,curmask}]!=0) return mp[{i,curmask}];
	if(i==m)
	{
		if(curmask==0) return 1;
		else return 0;
	}
	int res=0;
	vi nextmask;
	getnext(nextmask,curmask,0,0);
	for(int mask:nextmask)
	{
		res=(res+count(i+1,mask))%mod;
	}
	return mp[{i,curmask}]=res;
}
signed main()
{
		ios_base::sync_with_stdio(0);cin.tie(0);
		cin>>n>>m;
		if((n&1)&&(m&1))
		{
			cout<<0;
		}
		else
		cout<<count(0,0);

}