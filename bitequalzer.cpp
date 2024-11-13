#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	int c;
	cin>>c;
	string s,t;
	while(c--)
	{
		cin>>s>>t;
		int s0=0,s1=0,t0=0,t1=0;
		for(char i:s)
		{
			if(i=='0') ++s[0];
			if(i=='1') ++s[1];
		}
		for(char i:t)
		{
			if(i=='0') ++t[0];
			if(i=='1') ++t[1];
		}
		if(t1<s1)
		{
			cout<<"-1\n";
			continue;
		}else if(t1==s1)
		{
			int cnt=0;
			for(int i=0;i<s.size();++i)
			{
				if(t[i]=='1' && s[i]!='1')
					cnt++;
			}
			cout<<s.size()-s0-s1+cnt/2<<"\n";
		}else
		{
			int cv=t1-s1;
			for(int i=0;i<s.size() && cv;++i)
			{
				if(s[i]=='?' && t[i]=='1')
				{
					s[i]='1';
					cv--;
				}
			}
			for(int i=0;i<s.size() && cv;++i)
			{
				if(s[i]=='0' && t[i]=='1')
				{
					s[i]='1';
					cv--;
				}
			}
			if(cv)
			{
				
			}
		}


	}
}