#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> v(9,vector<int>(9));
pair<int,int> next(int i,int j){
	if(i==8 && j==8) return make_pair(-1,-1);
	if(j<8) return make_pair(i,j+1);
	return make_pair(i+1,0);

}
void try(int i, int j){
	if(i==-1) return;
	if(v[i][j]){
		tie(i,j)=next(i,j);
		try(i,j);
	}else{
		for(int k=1;k<=9;++k){
			
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	for(auto &l:v)
		for(&i: l) 
			cin>>i;


}