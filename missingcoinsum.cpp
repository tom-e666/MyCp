/*
idea: let's think about a good list of coin S, sum(S)= SUM,
given that all the value <=SUM can be constructed using S's subset
then, add another coin c into S, easy to tell now we can create all
value<= SUM+ c; until the list end, SUM+c+1 should be the first coin
sum that can't be built, only if c<=SUM, other wise SUM+1 will the the first coin sum
failed to construct
*/
#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	vector<int> v(n);
	for(auto &i : v) cin>>i;
	sort(all(v));
	if(v[0]!=1){
		cout<<1;
		return 0;
	}else{
		long long sum=v[0];
		v.erase(v.begin());
		for(auto i: v){
			if(i>sum+1) {
				break;
			}else{
				sum+=i;
			}
		}
		cout<<sum+1;


	}



}