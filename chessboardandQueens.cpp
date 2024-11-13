#include<bits/stdc++.h>
using namespace std;
vector<vector<bool>> reserved(9,vector(9,false));
vector<bool>vertical(9,0),diag1(18,0),diag2(18,0);
//diag1: x-y+8, diag2: x+y;
int cnt=0;
void place(int row=1)//row 1-8
{
	if(row==9){
		cnt++; return;
	}
	for(int y=1;y<=8;++y){
		if(reserved[row][y] ||vertical[y]
			||diag1[row-y+8] ||diag2[row+y])
			 continue;
		vertical[y]=1;
		diag1[row-y+8]=1;
		diag2[row+y]=1;
		place(row+1);
		vertical[y]=0;
		diag1[row-y+8]=0;
		diag2[row+y]=0;

	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	
	char c;
	for(int i=1;i<=8;++i)
		for(int j=1;j<=8;++j){
			cin>>c;
			if(c=='*') reserved[i][j]=1;
		}
	place();
	cout<<cnt;


	

}