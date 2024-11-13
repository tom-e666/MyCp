// #include<bits/stdc++.h>
// #define all(x) (x).begin(),(x).end()
// using namespace std;
// int main(){
// 	ios_base::sync_with_stdio(0);
// 	cin.tie(0);
// 	cout.tie(0);
// 	int n,m;
// 	cin>>n>>m;//ticket and customer
// 	vector<int> a(n,0),b(m,0);
// 	vector<int> c(n,0);
// 	for(auto &i :a) cin>>i;
// 	for(auto &i :b) cin>>i;
// 	sort(all(a));
// 	stringstream ss;
// 	for(auto i: b){
// 		if(auto x=upper_bound(all(a),i);x!=a.begin()){
// 			int p=x-a.begin();
// 			if(auto y=upper_bound(c.begin(),p+c.begin(),0);y!=c.begin()){
// 				y--;
// 				*y=1;
// 				p=y-c.begin();
// 				ss<<*(p+a.begin())<<"\n";
// 			}else{
// 				ss<<"-1\n";
// 			}
// 		}else{
// 				ss<<"-1\n";
// 		}
// 	}
// 	cout<<ss.str();
// }
#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m; //ticket and customer
    multiset<int, greater<int>> ticket_prices;
    for(int i = 0; i < n; i++) {
        int price;
        cin >> price;
        ticket_prices.insert(price);
    }
    for(int i = 0; i < m; i++) {
        int max_price;
        cin >> max_price;
        auto it = ticket_prices.lower_bound(max_price);
        if (it != ticket_prices.end()) {
            cout << *it << "\n";
            ticket_prices.erase(it);
        } else {
            cout << "-1\n";
        }
    }
    return 0;
}