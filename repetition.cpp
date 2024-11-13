#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	std::vector<char> v;
	char x;
	while(cin>>x){
		v.push_back(x);
	}
	int ans=INT_MIN;
	int t=0,i=0,s=v.size();
	while(i<s){
		x=v[i];
		t++;
		while(i<s-1 &&v[i+1]==x){
				t++;
				i++;
			}		
		ans=max(ans,t);
		t=0;
		i++;
	}
	cout<<ans;


}