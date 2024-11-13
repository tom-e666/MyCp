#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x=12345;
	double l=log10(x);
	cout<<l<<"\n"<<floor(l)<<"\n"<<pow(10,l-floor(l));
}