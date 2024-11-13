#include<bits/stdc++.h>
using namespace std;
bool check (string s)
{
	int res=0;
	reverse(s.begin(),s.end());
	for(int i=0;i<s.size();i+=1)
	{
		if(i&1)
		{
		int j=(s[i]-'0')*2;
		if(j>9) j=j%10+j/10;
		res+=j;
	}else
	{
		res+=s[i]-'0';
	}
	}

	return res%10==0;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		cout<<(check(s)?"PASS":"FAIL")<<"\n";
	}
}