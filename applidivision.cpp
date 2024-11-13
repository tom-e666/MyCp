#include<bits/stdc++.h>
using namespace std;
long long apple[21];
int n;
int k=0;
long long diff=INT_MAX;
long long s1=0,s2=0;
void permutate(int k){
	if(k==n){
		diff=min(diff,abs(s1-s2));
		return;
	}
	s1+=apple[k];
	permutate(k+1);
	s1-=apple[k];
	s2+=apple[k];
	permutate(k+1);
	s2-=apple[k];
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>apple[i];
	}
	permutate(0);
	cout<<diff;


}