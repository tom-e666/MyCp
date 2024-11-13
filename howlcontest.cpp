#include<bits/stdc++.h>
using namespace std;
int main()
{
	//can i omit making that kind of howl?
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	string s;
	cin>>s;
	char c=s[s.size()-1];
	if(c=='A')
	{
		s+="O";
		cout<< s+"O";
	}else if(c=='H')
	{
		cout<< s+"O";
	}
	else if (c=='O')
	{
		cout<< s+"H";
	}else{
		cout<< s+"H";
	}
}