//implementation (fundamental)
#include<bits/stdc++.h>
using namespace std;
#define ll long long
// class segment_tree{
// 	std::vector<ll> tree;
// 	void  contruct(const vector<ll>&a,int v, int tl, int tr)
// 	{	
// 		if(tl==tr)
// 		{
// 			tree[v]==a[tl];
// 		}else
// 		{
// 			//1_based indexing
// 			int m=(tl+tr)/2;
// 			contruct(a,2*v,tl,m);
// 			contruct(a,2*v+1,m+1,tr);
// 			tree[v]=tree[2*v]+tree[2*v+1];
// 		}
// 	}
// 	ll sum(int v, int tl, int tr, int l, int r)
// 	{
// 		if(tl==l && tr==r)
// 		{
// 			return tree[v];
// 		}else
// 		{
// 			int tm=(tl+tr)/2;
// 			return sum(v*2,tl,tm,l, min(r,tm))
// 				  +sum(v*2+1,tm+1,tr,max(l,tm+1),r);
// 		}

// 	}

// 	void update(int v, int tl, int tr,int pos, int val){
// 		if(tl==tr)
// 		{
// 			tree[v]=val;
// 		}else
// 		{
// 			int tm=(tl+tr)/2;
// 			if(pos<tm)
// 			{
// 				update(2*v,tl, tm, pos, val);
// 			}else
// 			{
// 				update(2*v+1,tm+1, tr, pos, val);
// 			}
// 			tree[v]=tree[2*v]+tree[2*v+1];
// 		}
// 	}
	
// };
class segmentTree
{ 
public:
	vector<int> smt;
	int n;
	segmentTree(vector<int>& a)
	{
		n=a.size();
		smt.resize(2*n);
		for(int i=0;i<n;++i)
		{
			smt[i+n]=a[i];
		}
		for(int j=n-1;j>0;--j)
		{
			smt[j]=smt[2*j]+smt[2*j+1];
		}
	}
	void update(int position,int value){
		smt[position+n]=value;
		int i=(position+n)/2;
		while(i>0)
		{
			smt[i]=smt[2*i]+smt[2*i+1];
			i/=2;
		}

	}
	int sum(int left, int right)
	{
		int res=0;
		left+=n;
		right+=n;
		while(left<=right)
		{
			if(left&1)
			{
				res+=smt[left];
				left++;
			}
			if(!(right&1))
			{
				res+=smt[right];
				right--;
			}
			left/=2;
			right/=2;


		}
		return res;

	}
};
int main() {
    vector<int> t{1, 2, 3, 3};
    segmentTree s(t);
    cout << s.sum(0, 3) << endl; // Output: 9

    s.update(2, 5);
    cout << s.sum(0, 3) << endl; // Output: 11

    return 0;
}
