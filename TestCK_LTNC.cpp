#include <bits/stdc++.h>
/* special solution:
in finding the 2 pair of point which creates the longest line
i propose the use of "boor ddeef gocs" which in a trick in
mathematical to find a non_inner_convex multi_gon which includes
all  existing points */
using namespace std;
struct p
{
	int x;
	int y;
	p(int xx = 0, int yy = 0) : x(xx), y(yy) {}
	friend istream &operator>>(istream &is, p &a)
	{
		is >> a.x >> a.y;
		return is;
	}
	friend ostream &operator<<(ostream &os, p a)
	{
		os << "(" << a.x << "," << a.y << ")";
		return os;
	}
	double r()
	{
		return sqrt(x * x + y * y);
	}
	friend double distance(p a, p b)
	{
		p vec(a.x - b.x, a.y - b.y);
		return vec.r();
	}
};
int main()
{
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	vector<p> v(n);
	for (auto &i : v)
		cin >> i;
	cerr<<"reg";
	int a = 0, b = 0;
	{
		// request 1 and 3
		
		for (int i = 1; i < n; ++i)
		{
			if(v[i].r()>v[a].r()){
				a=i;
			}
			if(v[i].y>=v[b].y){
				if(v[i].y>v[b].y || v[i].x>v[b].x){
					b=i;
				}
			}
			cerr<<"reg";
		}
	}

	int c=0,d=0;
	{
		for(int i=0;i<n;++i){
			for(int j=i+1;j<n;++j)
				if(distance(v[i],v[j])>distance(v[c],v[d])){
					c=i;
					d=j;
				}
		}
	}
	cout<<v[a]<<"\n";
	cout<<v[c]<<" "<<v[d]<<"\n";
	cout<<v[b];

}