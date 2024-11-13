#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define vi vector<int>
using namespace std;
//first sum, array on the right, array on the left

//1234    r=4
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int r,m,n;
	cin>>r>>m>>n;
	int x;
	vi pos(m),sl(r+2,0);//0 is null, r+1 also null, so to be 1...r
	for(auto &i:pos) cin>>i;
	long long now=0;	
	for(int i=0;i<m;++i)
	{
		cin>>x;
		sl[pos[i]+1]-=x;
		now+=x;
	}
	pos.resize(n);
	for(auto &i: pos) cin>>i;
	for(int i=0;i<n;++i)
	{
		cin>>x;
		sl[r-pos[i]+1]+=x;//add at the start of the posiion, which is.... r-pos[i]
	}
	long long res=INT_MIN;
	for(int i=1;i<=r;++i){
		now+=sl[i];
		res=max(now, res);
	}
	cout<<res;
}

