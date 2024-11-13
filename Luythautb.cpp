#include<bits/stdc++.h>
using namespace std;
const int mod= 1e9+7;

int power(int a, int b){ //faster a to the power of b (mod 1e9+7)
	if(b==0) return 1;
	int c= power(a,b/2);
	c=(1LL*c*c)%mod;
	 if (b & 1) {
        c = (1LL * c * a) % mod;
    }
    return c;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int a, b;
	cin>>a>>b;
	cout<<power(a,b);

}