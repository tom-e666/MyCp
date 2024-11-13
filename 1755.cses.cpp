#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<char, int> table;
    char x;
    
    // Read all characters from the input
    while (cin >> x) {
        table[x]++;
    }
    
    string res;
    char mid = '.';
    
    for (auto& p : table) {
        if (p.second % 2 == 1) {
            if (mid == '.') {
                mid = p.first;
                p.second--;
            } else {
                cout << "NO SOLUTION";
                return 0;
            }
        }
        res += string(p.second / 2, p.first);
    }
    
    string t = res;
    reverse(t.begin(), t.end());
    
    if (mid == '.') {
        cout << res <<t;
    } else {
        cout << res << mid<<t;
    }
    
    return 0;
}
