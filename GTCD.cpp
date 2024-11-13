#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
std::vector<long long> v(1e6+1,1);

int main(){
	for(int i=2;i<=1e6;++i){
		v[i]=( v[i-1]*i)%mod;
	}
	int t;
	cin>> t;
	int x;
	while(t--){
		cin>>x;
		cout<<v[x]<<"\n";
	}
}