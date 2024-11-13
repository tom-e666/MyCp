#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	std::vector<string> a{"0","1"},b,c;
	//douplicate and reverse
	for(int i=1;i<n;++i){
		b=a;
		for(auto &i:a)
		{
			i+="0";
		}
		for(auto it=b.rbegin();it<b.rend();++it)
		{
			a.emplace_back(*it+"1");
		}
	}
	for(auto &s: a)
		cout<<s<<"\n";

}