#include<bits/stdc_++.h>
using namespace std;
int main(){
	ios_base::sync_with_studio(0);
	cout.tie(0);
	int n;
	cin>>n;
	if(n<3){
		cout<<"NO";
	}else if(n==3){
		cout<<"YES";
	}else if(int t=n%4; t==2||t==1){
		cout<<"NO";
	}else{
		vector<int> v(n+1,false);
		int fst;
		if(t==0){
			for(int i=0;i<n;i+=4) {
				v[i+1]=v[i+4]=true;
			}
			fst=n/2;
		}else if(t==2){
			for(int i=0;i<n;i+=4){
				v[i+2]=v[i+3]=true;
			}
			//now the comparing part
			if(v[(n+1)/2]){//so it belongs to 2-3 parts
				
			}

		}
	}
}