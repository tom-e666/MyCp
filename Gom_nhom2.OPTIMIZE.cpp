#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;
uint_16t n, q;
vector<uint_16t> pr, sz;
vector<uint_16t> NEXT;
uint_16t FIND(uint_16t i) { // find parent
    if (pr[i] == i)
        return i;
    pr[i] = FIND(pr[i]);
    return pr[i];
}

void UNION(uint_16t i, uint_16t j) {
    uint_16t a = FIND(i);
    uint_16t b = FIND(j);
    if(a==b) return;
    if (b<a) //b is mama
    {
        pr[a] = b;
    	sz[b] += sz[a];	
    }
    else
    {
    	pr[b] = a;
    	sz[a] += sz[b];	
    }

    
    // //update the union
    // while(NEXT[a]<b && NEXT[a]!=a) a=NEXT[a];
    // if(NEXT[a]==a)
    // {
    // 	NEXT[a]=b;
    // }else
    // {
    // 	NEXT[b]=NEXT[a];
    // 	NEXT[a]=b;
    // }
    if(NEXT[a]==a && NEXT[b]==b){
    	if(a<b)
    	{
    		NEXT[a]=b;
    	}else
    	{
    		NEXT[b]=a;
    	}
    	return;
    }
    while(NEXT[a]!=a&&NEXT[b]!=b)
    {
    	if(a<b){
    		while(NEXT[a]!=a && NEXT[a]<b) a=NEXT[a];
    		uint_16t t=NEXT[a];
    		NEXT[a]=b;
    		a=t;
    	}else
    	{
    		while(NEXT[b]!=b && NEXT[b]<a) b=NEXT[b];
    		uint_16t t=NEXT[b];
    		NEXT[b]=a;
    		b=t;
    	}
    }
    //same incur: impossible
    if(NEXT[a]==a)
    {
    	while(NEXT[b]!=b && NEXT[b]<a) b=NEXT[b];
    }else if(NEXT[b]==b)
    {
    	while(NEXT[a]!=a && NEXT[a]<b) a=NEXT[a];
    }
    
	if(a<b)
	{
		NEXT[a]=b;
	}else
	{
		NEXT[b]=a;
	}
	return;
}
uint_16t q3(uint_16t a)
{
	uint_16t x= FIND(a);
	a=x;
	uint_16t first=-1;
	uint_16t second=-1;
	if(a==1)
	{
		while(a+1<=n&&NEXT[a]==a+1) a+=1;
		if(NEXT[a]==a)
		{
			//end;
			if(a+1<=n) {
				first=a+1;
				if(a+2<=n)
					second=a+2;
			}
			if(second==-1)
				return first;
			return second;
		}else
		{
		//when next[a] is not a+1
		first=a+1;
		
		if(NEXT[a]!=a+2)
		{
			return a+2;
		}
		a=NEXT[a];
		while(true)
		{
			if(FIND(a-1)!=x)
			{
				return a-1;
			}
			if(a+1<=n && FIND(a+1)!=x)
			{
				return a+1;
			}
			if(NEXT[a]==a) break;
			a=NEXT[a];
		}
		return first;
		}
	}
	else
	{
		//when a is not 1
		first=a-1;
		while(a+1<=n&&NEXT[a]==a+1) a+=1;
			if(a+1<=n && FIND(a+1)!=x)
			{
				return a+1;
			}
		a=NEXT[a];
		while(true)
		{
			if(FIND(a-1)!=x)
			{
				return a-1;
			}
			if(a+1<=n && FIND(a+1)!=x)
			{
				return a+1;
			}
			if(NEXT[a]==a) break;
			a=NEXT[a];
		}
		return first;
	}
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> q;
    pr.resize(n+1);
    sz.resize(n+1, 1);
    NEXT.resize(n+1);
    //fck, there is a break

    // init
    for (uint_16t i = 1; i <=n; ++i)
    {
     pr[i] = i;
     NEXT[i]=i;
	}

    // solution
    uint_16t p, a, b;
    while (q--) {
        cin >> p;
        if (p == 1) {
            cin >> a >> b;
            UNION(a  , b  );
        } else if (p == 2) {
            cin >> a;
            cout << sz[FIND(a)] << "\n";
        } else if (p == 3) {
        	cin>>a;
        	cout<<q3(a)<<"\n";
        }
    }
}