#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, x;
    cin >> n >> x;
    
    int h[1001], s[1001];
    
    for(int i = 1; i <= n; ++i) cin >> h[i];
    for(int i = 1; i <= n; ++i) cin >> s[i];
    
    int d[n + 1][x + 1]; 
    
    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j <= x; ++j) {
            d[i][j] = 0;
        }
    }
    
    for(int i = 1; i <= n; ++i) {
        int price = h[i];
        for(int j = 1; j <= x; ++j) {
            if(j >= price) {
                d[i][j] = max(d[i - 1][j], d[i - 1][j - price] + s[i]);
            } else {
                d[i][j] = d[i - 1][j];
            }
        }
    }
    
    cout << d[n][x] << endl;
    
    return 0;
}
