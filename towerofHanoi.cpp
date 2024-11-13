#include<bits/stdc++.h>
using namespace std;
int n;

void move(int root, int des, int size){
	if(size ==1){
		cout<<root<<" "<<des<<"\n";
		return;
	}
	move(root, 6-des-root,size-1);
	move(root,des,1);
	move(6-des-root,des,size-1);
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	cout<<pow(2,n)-1<<"\n";
	move(1,3,n);

}