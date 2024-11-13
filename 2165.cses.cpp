#include<bits/stdc++.h>
using namespace std;
stringstream ss;
int cnt=0;
void place(int departure, int arrival,int amount)
{
	if(amount==1)
	{
		ss<<departure<<" "<<arrival<<"\n";
		cnt++;
	}else
	{
		int temp=6-departure-arrival;
		place(departure,temp,amount-1);
		place(departure,arrival,1);
		place(temp,arrival,amount-1);
	}
}
int main()
{
	int n;
	cin>>n;
	place(1,3,n);
	cout<<cnt<<"\n";
	cout<<ss.str();
}