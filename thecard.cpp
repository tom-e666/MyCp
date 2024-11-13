#include<bits/stdc++.h>
using namespace std;

int gv(string s)
{
	return (isdigit(s[0])?s[0]-'0':10);
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int t;
	cin>>t;
	string v[60];
	int cs=1;
	while(t--)
	{
		string t;
		for(int i=0;i<52;++i) cin>>v[i];
		int y=0;
		int idx=26;
		for(int l=0;l<3;++l)
		{
			int val=gv(v[idx]);
			y+=val;
			idx-=11-val;
		}
		if(y-1<=idx)
		{
			cout<<"Case "<<cs++<<": "<<v[y-1]<<"\n";
		}else
		{
			cout<<"Case "<<cs++<<": "<<v[y-idx+25]<<"\n";
		}
	}
}