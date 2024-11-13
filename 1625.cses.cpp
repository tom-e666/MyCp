#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define loop(i,a,b) for(int i=a;i<b;++i)
#define ll long long
#define F first
#define S second
#define pii pair<int,int>
#define vi vector<int>
#define vl vector<long long>
bool v[9][9];
int dx[]={0,-1,0,1};
int dy[]={1,0,-1,0};
vector<int> g(48);
int Try(int ith,int x, int y)
{
	
		if(x==7 && y==1)
		{
			if(ith==48) return 1;
			return 0;
		}
	if((v[x-1][y]&&v[x+1][y]&&(!v[x][y-1])&&(!v[x][y+1])))
		return 0;
	if((!v[x-1][y])&&(!v[x+1][y])&&v[x][y-1]&&v[x][y+1])
		return 0;
	if(g[ith]<4)
	{
		int cnt=0;
		int nx=x+dx[g[ith]];
		int ny=y+dy[g[ith]];
		if(v[nx][ny])
			return 0;
		v[nx][ny]=1;
		 cnt=Try(ith+1,nx,ny);
		v[nx][ny]=0;
		return cnt;
	}else
	{
		int cnt=0;
		loop(d,0,4)
		{
			int nx=x+dx[d];
			int ny=y+dy[d];
			if(v[nx][ny])
				continue;
			v[nx][ny]=1;
			cnt+=Try(ith+1,nx,ny);
			v[nx][ny]=0;
		}
		return cnt;
	}
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	loop(j,0,9)
		{
			v[0][j]=1;
			v[8][j]=1;
		}
	loop(i,0,9)
	{
		v[i][0]=1;
		v[i][8]=1;
	}
	loop(i,1,7)
	loop(j,1,7)
	v[i][j]=0;

	string line;
	cin>>line;
	loop(i,0,48)
	{
		char c=line[i];
		if(c=='R')
		{
			g[i]=0;
		}else if(c=='U')
		{
			g[i]=1;
		}else if(c=='L')
		{
			g[i]=2;
		}else if(c=='D')
		{
			g[i]=3;
		}else
		{
			g[i]=4;
		}
	}
	v[1][1]=1;
	int res=Try(0,1,1);
	cout<<res;
}