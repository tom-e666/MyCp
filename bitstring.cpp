#include<bits/stdc++.h>
const int M=1e9+7;
using namespace std;
unsigned long long power(unsigned long long a, unsigned long long x){
	unsigned long long ans=1;
	while(x){
		if(x%2==1){
			ans*=a;
			ans%=M;
		}
		a*=a;
		a=a%M;
		x/=2;
	}
	return ans;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	cout<<power(2,n);
}