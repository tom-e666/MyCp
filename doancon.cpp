#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,c,t;
	cin>>n>>t>>c;
	vector<int> a(n,0);
	for(auto &i:a) cin>>i;
	int i=0,j;
	vector<int> l;
	while(i<n){
		while( i<n && a[i]>t) i++;
		if(i>=n) break;
		j=i;
		while(j+1<n && a[j+1]<=t) j++;
		if(j-i+1>=c) l.push_back(j-i+2-c);
		i=j+1;
	}
	int ans=0;
	for(auto i: l) ans+=i;
	cout<<ans;
}