#include<bits/stdc++.h>
using namespace std;
int gcd(int x, int y){
	if(y==0) return x;
	return gcd(y,x%y);
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;

	vector<int> v(n);
	for(int i=0;i<n;++i) cin>>v[i];
	
	sort(v.begin(),v.end());
	int i=0;
	while(i<n){
		for(int j=i+1;j<n;++j){
			if(gcd(v[j],v[i])!=1){
				swap(v[j],v[n-1]);
				n--;
			}
			
		}
		if(gcd(v[i+1],v[i])!=1){
				swap(v[i+1],v[n-1]);
				n--;
			}
		v.resize(n);
		i++;
	}
	cout<<v.size();
	

}