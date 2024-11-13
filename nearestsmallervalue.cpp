#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &i : v) cin >> i;

    vector<int> dp(n);
    dp[0] = -1;

    for(int i = 1; i < n; ++i){
        if(v[i] == v[i-1]) 
            dp[i] = dp[i-1];  // Changed this line
        else if(v[i] > v[i-1]) 
            dp[i] = i-1;  // Changed this line
        else {
            int j = dp[i-1];
            while(j > 0){
                if(v[i] == v[j]){
                    dp[i] = dp[j];
                    break;
                } else if(v[i] > v[j]){
                    dp[i] = j;
                    break;
                } else {
                    j = dp[j];
                }
            }
            if(j == 0) dp[i] = -1;
        }
    }

    for(auto i : dp) 
        cout << i +1<< " ";
}
