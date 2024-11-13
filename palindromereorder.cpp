#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> v(256, 0);  // Use a larger size for ASCII characters
    set<int> dex;
    char c;

    // Read characters until the end of input
    while (cin >> c) {
    	dex.insert(c);    
        v[c]++;
    }

    // Remove duplicates from dex
    

    string l, r;
    int odd_pos = -1;

    for (auto i : dex) {
        if (v[i] % 2 == 1) {
            if (odd_pos != -1) {
                cout << "NO SOLUTION";
                return 0;
            }
            odd_pos = i;
        } else {
            l += string(v[i] / 2, (char)i);
            r = string(v[i] / 2, (char)i) + r;
        }
    }

    if (odd_pos != -1) {
        l += string(v[odd_pos], (char)odd_pos);
    }
    
    cout <<l+r;
    
    
    return 0;
}
