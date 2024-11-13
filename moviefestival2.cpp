#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin>>n>>k;

	vector<pair<int,int>>v(n);
	for(auto &i:v) cin>>i.first>>i.second;
	sort(begin(v),end(v),[](pair<int,int> x,pair<int,int> y){
		if(x.second==y.second) return x.first<y.first;
		return x.second<y.second;
	});
	vector<int> w(k,0);
	int m=0;
	int cnt=0;
	int j;
	while(m<n){
		j=min(k,n-m);
		for(int i=0;i<j;++i){
			if(w[i]<=v[m].first){
				w[i]=v[m].second;
				cnt++;
			}
			m++;
		}
	}
	cout<<cnt;
	

}