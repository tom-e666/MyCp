#include<bits/stdc++.h>
using namespace std;
int n;
int t,q;
int xl,xr,yl,yr,zl,zr;
string s;
void update();
long long query();
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>t;
	while(t--)
	{
		cin>>n>>q;
		long long[] arr[n+1][n+1];
		while(q--)
		{
			cin>>s;
			if(s=='UPDATE')
			{
				cin>>x>>y>>z>>m;
				update(arr,x,y,z,m);
			}else if(s=='QUERY')
			{
				cin>>xl>>xr>>yl>>yr>>zl>>zr;
				cout<<query(arr,xl,xr,yl,yr,zl,zr);
			}


		}

	}



}