#include<bits/stdc++.h>
#define ll long long
#define what(x) cout<<#x<<" is "<<x;
#define pb push_back
#define vi std::vector<int>
#define vii vector<vector<int>>
#define sort(v) sort(begin(v),end(v))
using namespace std;

/*
grid path solution notice 1
 */
vector<char> path(48,'');
vector<bool> vector<vector<bool> visited(7,(7,0)){1};
int ans=0;
int x=6,y=6;
bool isEnd()=[x,y](){
	return (x==0)&&(y==0);
}
bool IsOkay_naive(int x, int y){
	if(visited(x,y)) return false;
	if( x<0 || x>6 ) return false;
	if(y<0 || y>6) return false;
	return true
}
bool IsOkay(){
	if(!IsOkay_naive(x,y)) return false;
	int c=0;
	if(IsOkay_naive(x+1,y)) c++;
	if(IsOkay_naive(x-1,y)) c++;
	if(IsOkay_naive(x,y+1)) c++;
	if(IsOkay_naive(x,y-1)) c++;
	if(c==0) return false;
	if(c==2){
		
	}
}

void try(int index){
	if(index==48 && isEnd()) {
		cnt++;
		return;
	}
	switch(path[index]){
	case 'D':
		x--;	
		if(IsOkay()) try(index+1);
		x++;
		break;
	case 'U':
		x++;	
		if(IsOkay()) try(index+1);
		x--;
		break;
	case 'L':
		y--;
		if(IsOkay()) try(index+1);
		y++;
		break;
	case 'R':
		y++;
		if(IsOkay()) try(index+1);
		y--
		break;
	default:
		x--;	
		if(IsOkay()) try(index+1);
		x++;
		x++;	
		if(IsOkay()) try(index+1);
		x--;
		y--;
		if(IsOkay()) try(index+1);
		y++;
		y++;
		if(IsOkay()) try(index+1);
		y--
	 //case '?'
		break;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	char c;
	for(auto &i:path) {
		cin>>c;
	}
	try(0);
	cout<<cnt;


	
}