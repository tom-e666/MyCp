#include<bits/stdc++.h>
using namespace std;
int main(){
	//repetition
	string input;
	cin>>input;
	int n=input.size();
	int i=0;
	int res=INT_MIN;
	while(i<n){
		int start=i;
		char c=input[i];
		while(i<n-1 &&input[i+1]==c) i++;
		res=max(res,i-start+1);
		i++;
	}
	cout<<res;
}
