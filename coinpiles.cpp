#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int ts;
	cin>>ts;
	int a,b;
	while(ts--){
		cin>>a>>b;
		if((a+b)%3==0 &&min(a,b)*2>=max(a,b))		{
			cout<<"YES";
		}else{
			cout<<"NO";
		}
		cout<<"\n";
	}
}