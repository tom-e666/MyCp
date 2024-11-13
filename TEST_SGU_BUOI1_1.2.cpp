#include<bits/stdc++.h>
using namespace std;
define ull unsigned long long
ull mult(ull a, ull b, ull c){
	//idea: watch b: [b/2]*2 +(b+1)%2
	if(b==1){
		return a%c;
	}
	if(b==0) return 0;
	ull d=mul(a,b/2,c);
	d=(d+d)%c;
	if(c%2==0){
		return d;
	}else{
		return (d+a)%c;
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	ull a,b,c;
	cin>>a>>b>>c;
	cout<<mult(a,b,c);
}
