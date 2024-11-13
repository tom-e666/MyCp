#include<bits/stdc++.h>
using namespace std;

int main(){
	enum direction {TOP,BOTTOM, RIGHT, LEFT};
	//spiral with enumeration
	int n;
	cin>>n;
	std::vector<vector<int>> res(n,vector<int>(n));
	int cnt=1;
	int left=0;
	int right=n-1;
	int top=0;
	int bottom=n-1;
	direction dir=RIGHT;
	while(left<=right && top<=bottom){
		switch (dir){
			case RIGHT:
				for(int y=left;y<=right;++y)
					res[top][y]=cnt++;
				top++;
				dir=BOTTOM;
				break;
			case BOTTOM:
				for(int x=top;x<=bottom;++x)
					res[x][right]=cnt++;
				right--;
				dir=LEFT;
				break;
			case LEFT:
				for(int y=right;y>=left;--y)
					res[bottom][y]=cnt++;
				bottom--;
				dir=TOP;
				break;
			case TOP:
				for(int x=bottom;x>=top;--x)
					res[x][left]=cnt++;
				left++;
				dir=RIGHT;
				break;
		}
	}
	for(auto line: res)
	{
		for(auto c: line) cout<< c<<" ";
		cout<<"\n";
	}
}
/*
SHORTER CODE:
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
         //init 0,0; shift then assign 
        vector<vector<int>>res(n,vector<int>(n));
        int cnt=1;//up do n^2
        int a,b,c,d;
        a=n-1;b=n-1;c=0;d=1;//outer limit
        int x=0,y=0;
        res[0][0]=cnt++;
        while(cnt<=n*n){
            while(y<a){//0 1 2
                y++;
                res[x][y]=cnt++;
            }
            a--;
            while(x<b){
                x++;
                res[x][y]=cnt++;
            }
            b--;

            while(y>c){
                y--;
                res[x][y]=cnt++;
            }
            c++;
            while(x>d){
                x--;
                res[x][y]=cnt++;
            }
            d++;
        }
        return res;
    }
};
*/