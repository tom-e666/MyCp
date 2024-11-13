#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int cnt=0;
	while(n){
		cnt+=n/5;
		n/=5;
	}
	cout<<cnt;

}