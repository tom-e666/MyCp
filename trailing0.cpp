#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	long long a=0;
	long long b=0;
	for(int i=1;i<=log(n)/log(2);++i){
		a+=n/pow(2,i);
	}
	for(int i=1;i<=log(n)/log(5);++i){
		b+=n/pow(5,i);
	}
	cout<<min(a,b);
	
}