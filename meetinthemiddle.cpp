#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> fn(vector<int> v){//permutation
	vector<int> ans{0};
	vector<int> tmp;
	for(auto i :v){
		for(auto j: ans){
			tmp.push_back(j+i);
		}
		ans.insert(ans.end(),begin(tmp),end(tmp));
		tmp.clear();
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, x;
	cin >> n >> x;
	vector<int> v(n, 0);
	for(auto &i: v) cin >> i;		
	vector<int> a=fn(vector<int>(v.begin(), v.begin() + n/2));
	vector<int> b=fn(vector<int>(v.begin() + n/2, v.end()));
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());

	int cnt = 0;
	// int i = a.size() - 1;
	// int j = b.size() - 1;
	// while(i >= 0 && j >= 0){
	// 	if(a[i] + b[j] > x){
	// 		i--;
	// 	}else if(a[i] + b[j] < x){
	// 		j--;
	// 	}else{
	// 		int X=1;
	// 		int Y=1;
	// 		while(i>=0 &&a[i-1]==a[i]){
	// 			i--;
	// 			X++;
	// 		}
	// 		while(j>=0 &&b[j-1]==b[j]){
	// 			j--;
	// 			Y++;
	// 		}
	// 		cnt+=x*y;
	// 	}
	// }
	for(auto i: a){
		cnt+=upper_bound(begin(b),end(b),x-i)-lower_bound(begin(b),end(b),x-i);
	}
	cout << cnt;
	return 0;
}
