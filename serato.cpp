#include<bits/stdc++.h>
using namespace std;
vector<int> serato(1e5+1,1);
void siege(){
	serato[2]=1;
	for(int i=2;i<1e5+1;++i)
	{
		if(serato[i]==1)
		{
			for(int j=i;j<1e5+1;j+=i)
			{
				if(serato[j]==1)
				{
					serato[j]=i;
						
				}
			}
		}

	}
}
vector<int> defactor(int a)
{
	if(a==1)
	{
		return vector<int>{a};
	}
	vector<int> res;
	while(a!=1)
	{
		res.emplace_back(serato[a]);
		a/=serato[a];
	}
	return res;
}

int main()
{
	siege();
	
	vector<int> t=defactor(100);
	for(auto& i: t) cout<<i<<" ";

}