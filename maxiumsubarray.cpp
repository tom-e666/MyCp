#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	vector<int> v(n,0);
	for(auto &i :v) cin>>i;
	vector<long long> s(n,0);
	s[0]=v[0];
	for(int i=1;i<n;++i){
		s[i]=max(1ll*v[i],1ll*v[i]+s[i-1]);
	}
	cout<<*max_element(begin(s),end(s));

}