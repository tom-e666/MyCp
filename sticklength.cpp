#include<bits/stdc++.h>
using namespace std;
long long fn(vector<int> v, int x){
	long long s=0;
	for(auto i: v) s+=abs(i-x);
	return s;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	vector<int> v(n,0);
	for(auto &i: v) cin>>i;
	sort(begin(v),end(v));
	int s=0;
	if(n%2==1){
		cout<<fn(v,v[n/2]);
	}else{
		cout<<min(fn(v,v[n/2]-1),fn(v,v[n/2]));
	}
}