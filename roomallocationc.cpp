/*
 1st approach: using the concert attending problem as the base solver
 may be using the policy-based indexing is better, but for now the coder
 didn't know how to wrote it


 result, as this is not a good approach, i expect this result will happen
 the code welled handle hack cases and LTE on heavy load, that said
 i code it well but this not a full score submission 
*/
#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define pii pair<int,int>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	vector<pair<int,pii>>v(n);
	for(int i=0;i<n;++i){
		v[i].first=i;
		cin>>v[i].second.first>>v[i].second.second;
	}
	sort(all(v),[](pair<int,pii> x, pair<int,pii> y)->bool{
		if(x.second.second==y.second.second)
			return x.second.first<y.second.first;
		return x.second.second<y.second.second;
	});
	vector<int> ans(n);
	int cnt=0;
	while(v.size()){
		cnt++;
		int t=v[0].second.second;
		ans[v[0].first]=cnt;
		v.erase(v.begin());
		int sz=v.size();
		if(sz==0) break;
		for(int i=0;i<sz;++i){
			if(t<v[i].second.first){
				ans[v[i].first]=cnt;
				t=v[i].second.second;
				v.erase(v.begin()+i);
			}
		}
	}
	cout<<cnt<<"\n";
	for(auto i: ans) cout<<i<<" ";









}