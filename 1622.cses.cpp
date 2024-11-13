#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	sort(s.begin(),s.end());
	stringstream ss;
	int cnt=1;
	ss<<s<<" ";
	while(next_permutation(s.begin(),s.end())){
		ss<<s<<" ";
		cnt++;
	}
	cout<<cnt<<"\n"<<ss.str();



}