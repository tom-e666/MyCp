#include<bits/stdc++.h>
const long long M=1e9+7;
using namespace std;
int m,n;
std::vector<long long> d(102,0),pre(102,0);
	void fn(int x){
		if(x!=0){
			for(int i=1;i<=m;++i) pre[i]=x;
			return;
		}
		//x==0;
		pre[0]=(d[0]+d[1])%M;
		for(int i=1;i<=m;++i){
			pre[i]=(d[i-1]+d[i]+d[i+1])%M;
		}
		d=pre;
		for(int i=0;i<=m;++i){
			pre[i]=i;
		}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;	
	int x;
	cin>>x;
	fn(x);
	if(x!=0) fill(begin(d),end(d),1);
	for(int i=2;i<=n;++i) {
		cin>>x;
		fn(x);
	}
	long long ans=0;
	for(int i=0;i<=m;++i){
		ans=(ans+d[i])%M;
	cout<<ans;

}