#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	vector<pair<int,int>> v(n);
	for(auto &i:v) cin>>i.first>>i.second;
	sort(begin(v),end(v));
	long long t=0,rew=0;
	for(auto i: v){
		t+=i.first;
		rew+=i.second-t;
	}
	cout<<rew;
}