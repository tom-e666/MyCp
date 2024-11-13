// //lazy propagation variation
// #include<bits/stdc++.h>
// using namespace std;

// int main(){
// 		int n,q;
// 		cin>>n>>q;
// 		vector<long long>smt(2*n);
// 		for(int i=0;i<n;++i)
// 		{
// 			cin>>smt[i+n];
// 		}
// 		int x,a,b,k;
// 		long long u;
// 		while(q--){
// 			cin>>x;
// 			if(x==1)
// 			{
// 				cin>>a>>b>>u;
// 				a-=1;
// 				b-=1;

// 				a+=n;
// 				b+=n;
// 				while(a<=b){
// 					if(a&1)
// 					{
// 						smt[a]+=u;
// 						a++;
// 					}
// 					if(!(b&1))
// 					{
// 						smt[b]+=u;
// 						b--;
// 					}
// 					a/=2;
// 					b/=2;
// 				}
// 			}
// 			if(x==2)
// 			{
// 				cin>>k;
// 				k-=1;
// 				k+=n;
// 				long long res=0;
// 				while(k>0){
// 					res+=smt[k];
// 					k/=2;
// 				}
// 				cout<<res<<'\n';
// 			}
// 		}
// }


#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<long long> smt(2 * n, 0);

    // Reading initial values
    for (int i = 0; i < n; ++i) {
        cin >> smt[i + n];
    }

    // Handling queries
    while (q--) {
        int x;
        cin >> x;

        if (x == 1) { // Range update
            int a, b;
            long long u;
            cin >> a >> b >> u;
            a += n - 1;
            b += n - 1;

            // Range update with lazy propagation
            for (int i = a; i <= b; i++) {
                smt[i] += u;
            }
        } else if (x == 2) { // Point query
            int k;
            cin >> k;
            k += n - 1;
            long long res = 0;

            // Summing up the values from the leaf to the root
            while (k > 0) {
                res += smt[k];
                k /= 2;
            }
            cout << res << '\n';
        }
    }

    return 0;
}
