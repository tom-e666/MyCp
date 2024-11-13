#include<bits/stdc++.h>
using namespace std;
int main()
{
	int m,n,k;
	cin>>m>>n>>k;
	vector<int>desire(m),sz(n);
	for(int i=0;i<m;++i)
		cin>>desire[i];
	for(int i=0;i<n;++i)
		cin>>sz[i];
	sort(desire.begin(),desire.end());
	sort(sz.begin(),sz.end());
	//try to assign houses;
	int x=0,y=0,cnt=0;
	while(x!=m && y!=n)
	{
		if(int t=abs(desire[x]-sz[y])<=k)
		{
			x++;
			y++;
			cnt++;
		}else
		{
			if(desire[x]<sz[y])
			{
				x++;
			}else
			{
				y++;
			}
		}
	}
	cout<<cnt;

}