#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	map<char,int> mp;
	for(auto i: s ) mp[i]++;
	for(auto i: mp) 
		if(i.second==1){
			cout<<i.first;
		}else{
			cout<<i.second<<i.first;
		}

}