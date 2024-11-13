#include<bits/stdc++.h>
using namespace std;
const int sz=1e6;
bool is_ele( int n){
	//eratos siege
	static vector<bool> v(sz,true);
	static int rsz= sqrt(sz);
	if(v[0]){//structure the siege
		v[0]=v[1]=false;
		v[2]=v[3]=true;

		for(int i=2;i<=rsz;++i){
			if(v[i]){
				for(int j=i*2;j<sz;j+=i)
					v[j]=false;
			}
		}
	}
	return v[n];
}
int main(){
	for(int i=0;i<sz;++i){
		if(is_ele(i))
			cout<<i <<" ";
	}
}