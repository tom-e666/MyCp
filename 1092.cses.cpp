#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	if(n<=2)
	{
		cout<<"NO";
		return 0;
	}
	if(n==3)
	{
		cout<<"YES\n";
		cout<<"2\n1 2\n 1\n3";
		return 0;
	}
	if(int t=n%4;t==2||t==1)
	{
		cout<<"NO";
		return 0;
	}else if(t==0)
	{
		cout<<"YES\n"<<n/2<<"\n";

		for(int i=0;i<n;i+=4){
			cout<<i+1<<" "	<<i+4<<" ";
		}
		cout<<n/2<<"\n";
		for(int i=0;i<n;i+=4){
			cout<<i+2<<" "	<<i+3<<" ";
		}
	}else //for sure the situation is 4k+3;->(4k+3)(k+1)%2==0
	{
		//recur: 4567 -> 47 56, then 4(k-1)+3... then 12, 3
		cout<<"YES\n"<<n/2+1<<"\n1 2 ";
		for(int i=4;i<n;i+=4){
			cout<<i<<" "<<i+3<<" ";
		}
		cout<<"\n"<<n/2<<"\n3 ";
		for(int i=4;i<n;i+=4){
			cout<<i+1<<" "<<i+2<<" ";
		}
	}


}