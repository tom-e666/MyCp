#include<bits/stdc++.h>
using namespace std;
vector<vector<bool>> v(8,vector<bool>(8));
//maintain 3 array
vector<bool> diag_a(15),diag_b(15),col(8);
int cnt=0;
void place_queen(int row)//row 0 to 7
{
	if(row==8) {
		cnt++;
		return;
	}
		
	for(int j=0;j<8;++j)	
	{
		if(col[j]==false && diag_a[row+j]==false && diag_b[row-j+7]==false && v[row][j]==false)
		{
			col[j]=true;
			diag_a[row+j]=true;
			diag_b[row-j+7]=true;
			place_queen(row+1);
			col[j]=false;
			diag_a[row+j]=false;
			diag_b[row-j+7]=false;
		}
	}
}

int main()
{

	
	char x;
	for(int i=0;i<8;++i)
		for(int j=0;j<8;++j)
		{
			cin>>x;
			if(x=='*') v[i][j]=true;
		}
	place_queen(0);
	cout<<cnt;



}