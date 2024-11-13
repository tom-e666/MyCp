#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	unsigned long long s=0;
	int n;
	cin>>n;
	int pre;
	int x;
	cin>>pre;
	for(int i=1;i<n;++i){
		cin>>x;
		if(x<pre) s+=pre-x;
		else pre=x;
	}
	cout<<s;
}	