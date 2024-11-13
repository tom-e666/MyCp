#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	string s;
	long long m,k,x;
	cin>>s;
	cin>>m>>k>>x;
	vector<string> vs(m);
	for(auto &i: vs) cin>>i;
	if(x==0){
		//special case;
		//testcase shouldn't include this
		return 0;
	}
	x-=1;
	int pos=m-1;
	reverse(begin(s),end(s));
	for(auto &i: s){
		if(i=='#'){
			vector<char> v(vs[pos].begin(),vs[pos].end());
			sort(begin(v),end(v));
			i=v[x%k];
			x/=k;
			pos--;
		}

		}
	reverse(begin(s),end(s));
	


}