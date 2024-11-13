#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	// while(n--){
	//     int x;
	//     cin>>x;
	//     for(int i=0;(1<<i)<=x;++i){
	//         x^=(1<<i);
	//     }
	//     cout<<x<<"\n";
	// }
	while (n--)
	{
		int x;
		cin >> x;
		int k = ceil(log(x + 1) / log(2));
		cout << (1 << k) - 1 - x << "\n";
	}
}