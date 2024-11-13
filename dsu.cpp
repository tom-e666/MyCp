#include<bits/stdc++.h>
using namespace std;
void make_set(int a){
	parent[a]=a;
	sz[v]=1;
}
int find_set(int a){
	if(a==parent(a)) return a;
	return find_set(parent[a]);
}
void union_set(int a, int b){
	int x= find_set(a);
	int y=find_set(b);
	if(x!=y){
		if(sz[x]<sz[y]) swap(x,y);
		parent[y]=x;
		sz[x]+=sz[y];
	}

}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);	
}