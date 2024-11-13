#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;
	long long x;long long y;
	cin>>t;
	for(int i=0;i<t;++i){
		cin>>x>>y;
		if(x<y){
			if(y%2==1){
				cout<<y*y-y+1+(y-x);
			}else{
				cout<<y*y-y+1-(y-x);
			}
		}else{
			if(x%2==1){
				cout<<x*x-x+1-(x-y);
			}else{
				cout<<x*x-x+1+(x-y);
			}
		}
		cout<<"\n";
		
	}
	
}